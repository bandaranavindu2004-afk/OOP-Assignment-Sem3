#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <string>
#include <map>
#include <vector>

using namespace std;

template <typename T>
class Repository {
private:
    map<string, T*> data;

public:
    Repository() = default;
    ~Repository();

    Repository(const Repository&) = delete;
    Repository& operator=(const Repository&) = delete;

    void add(string id, T* entity);
    void remove(string id);
    T* find(string id);
    vector<T*> getAll();
};


// Destructor
template <typename T>
Repository<T>::~Repository() {
    for (auto& item : data) {
        delete item.second;
    }
}


// Add
template <typename T>
void Repository<T>::add(string id, T* entity) {
    data[id] = entity;
}


// Remove
template <typename T>
void Repository<T>::remove(string id) {
    auto it = data.find(id);

    if (it != data.end()) {
        delete it->second;
        data.erase(it);
    }
}


// Find
template <typename T>
T* Repository<T>::find(string id) {
    auto it = data.find(id);

    if (it != data.end()) {
        return it->second;
    }

    return nullptr;
}


// Get all
template <typename T>
vector<T*> Repository<T>::getAll() {
    vector<T*> result;

    for (auto& item : data) {
        result.push_back(item.second);
    }

    return result;
}

#endif