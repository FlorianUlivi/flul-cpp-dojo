#ifndef CPP_DOJO_EXPERIMENT_REGISTRY_HPP
#define CPP_DOJO_EXPERIMENT_REGISTRY_HPP

#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <utility>

namespace cpp_dojo {

class ExperimentRegistry {
   public:
    class Builder;

    static ExperimentRegistry& Instance() {
        static ExperimentRegistry instance;
        return instance;
    }

    void RegisterExperiment(const std::string& name, std::function<void()> fn) {
        experiments_[name] = std::move(fn);
    }

    void RunAll() {
        for (const auto& [name, fn] : experiments_) {
            std::cout << "=== " << name << " ===" << '\n';
            fn();
            std::cout << '\n';
        }
    }

    [[nodiscard]] std::size_t Count() const {
        return experiments_.size();
    }

    [[nodiscard]] bool Contains(const std::string& name) const {
        return experiments_.contains(name);
    }

    void Clear() {
        experiments_.clear();
    }

    ExperimentRegistry(const ExperimentRegistry&) = delete;
    ExperimentRegistry& operator=(const ExperimentRegistry&) = delete;
    ExperimentRegistry(ExperimentRegistry&&) = delete;
    ExperimentRegistry& operator=(ExperimentRegistry&&) = delete;

   private:
    ExperimentRegistry() = default;
    ~ExperimentRegistry() = default;

    std::map<std::string, std::function<void()>> experiments_;
};

class ExperimentRegistry::Builder {
   public:
    explicit Builder(std::string name) : name_(std::move(name)) {}

    void Execute(std::function<void()> fn) {
        ExperimentRegistry::Instance().RegisterExperiment(name_, std::move(fn));
    }

    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

   private:
    std::string name_;
};

}  // namespace cpp_dojo

#endif  // CPP_DOJO_EXPERIMENT_REGISTRY_HPP
