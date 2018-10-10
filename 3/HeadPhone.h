#ifndef HeadPhone_h
#define HeadPhone_h


class HeadPhone {

 public:

    virtual String getManufacturer();

    virtual Integer getYear();

    virtual Integer getMagnetSize();

    virtual String getModelName();

    HeadPhone(String manufact, String name, Integer makeYear, Integer magnet);


 private:
    String manufacturer;
    Integer year;
    Boolean isInited;
    Integer magnetSize;
    String modelName;
};

#endif // HeadPhone_h
