#ifndef HeadPhoneManufacturer_h
#define HeadPhoneManufacturer_h

#include <vector>

#include "HeadPhone.h"


class HeadPhoneManufacturer {

 public:

    HeadPhoneManufacturer(String name);

    virtual void addModel(String modelName, Integer makeYear, Integer magnetSize);

    virtual HeadPhone getModel(String modelName);

    virtual void deleteModel(String modelName);

 public:
    std::vector< HeadPhone > models;

 private:
    String companyName;
};

#endif // HeadPhoneManufacturer_h
