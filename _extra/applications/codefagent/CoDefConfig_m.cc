//
// Generated file, do not edit! Created by nedtool 5.6 from inet/_extra/applications/codefagent/CoDefConfig.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include "CoDefConfig_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace {
template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)(static_cast<const omnetpp::cObject *>(t));
}

template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && !std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)dynamic_cast<const void *>(t);
}

template <class T> inline
typename std::enable_if<!std::is_polymorphic<T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)static_cast<const void *>(t);
}

}

namespace inet {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule to generate operator<< for shared_ptr<T>
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const std::shared_ptr<T>& t) { return out << t.get(); }

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');

    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

IntConfigValue::IntConfigValue()
{
    this->maxValue = 0;
    this->minValue = 0;
    this->currentValue = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const IntConfigValue& a)
{
    doParsimPacking(b,a.maxValue);
    doParsimPacking(b,a.minValue);
    doParsimPacking(b,a.currentValue);
}

void __doUnpacking(omnetpp::cCommBuffer *b, IntConfigValue& a)
{
    doParsimUnpacking(b,a.maxValue);
    doParsimUnpacking(b,a.minValue);
    doParsimUnpacking(b,a.currentValue);
}

class IntConfigValueDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_maxValue,
        FIELD_minValue,
        FIELD_currentValue,
    };
  public:
    IntConfigValueDescriptor();
    virtual ~IntConfigValueDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(IntConfigValueDescriptor)

IntConfigValueDescriptor::IntConfigValueDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::IntConfigValue)), "")
{
    propertynames = nullptr;
}

IntConfigValueDescriptor::~IntConfigValueDescriptor()
{
    delete[] propertynames;
}

bool IntConfigValueDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IntConfigValue *>(obj)!=nullptr;
}

const char **IntConfigValueDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IntConfigValueDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IntConfigValueDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int IntConfigValueDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_maxValue
        FD_ISEDITABLE,    // FIELD_minValue
        FD_ISEDITABLE,    // FIELD_currentValue
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *IntConfigValueDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "maxValue",
        "minValue",
        "currentValue",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int IntConfigValueDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "maxValue") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "minValue") == 0) return base+1;
    if (fieldName[0] == 'c' && strcmp(fieldName, "currentValue") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IntConfigValueDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16",    // FIELD_maxValue
        "uint16",    // FIELD_minValue
        "uint16",    // FIELD_currentValue
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **IntConfigValueDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *IntConfigValueDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int IntConfigValueDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IntConfigValue *pp = (IntConfigValue *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IntConfigValueDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IntConfigValue *pp = (IntConfigValue *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IntConfigValueDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IntConfigValue *pp = (IntConfigValue *)object; (void)pp;
    switch (field) {
        case FIELD_maxValue: return ulong2string(pp->maxValue);
        case FIELD_minValue: return ulong2string(pp->minValue);
        case FIELD_currentValue: return ulong2string(pp->currentValue);
        default: return "";
    }
}

bool IntConfigValueDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IntConfigValue *pp = (IntConfigValue *)object; (void)pp;
    switch (field) {
        case FIELD_maxValue: pp->maxValue = string2ulong(value); return true;
        case FIELD_minValue: pp->minValue = string2ulong(value); return true;
        case FIELD_currentValue: pp->currentValue = string2ulong(value); return true;
        default: return false;
    }
}

const char *IntConfigValueDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *IntConfigValueDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IntConfigValue *pp = (IntConfigValue *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

DoubleConfigValue::DoubleConfigValue()
{
    this->maxValue = 0;
    this->minValue = 0;
    this->currentValue = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const DoubleConfigValue& a)
{
    doParsimPacking(b,a.maxValue);
    doParsimPacking(b,a.minValue);
    doParsimPacking(b,a.currentValue);
}

void __doUnpacking(omnetpp::cCommBuffer *b, DoubleConfigValue& a)
{
    doParsimUnpacking(b,a.maxValue);
    doParsimUnpacking(b,a.minValue);
    doParsimUnpacking(b,a.currentValue);
}

class DoubleConfigValueDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_maxValue,
        FIELD_minValue,
        FIELD_currentValue,
    };
  public:
    DoubleConfigValueDescriptor();
    virtual ~DoubleConfigValueDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(DoubleConfigValueDescriptor)

DoubleConfigValueDescriptor::DoubleConfigValueDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::DoubleConfigValue)), "")
{
    propertynames = nullptr;
}

DoubleConfigValueDescriptor::~DoubleConfigValueDescriptor()
{
    delete[] propertynames;
}

bool DoubleConfigValueDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DoubleConfigValue *>(obj)!=nullptr;
}

const char **DoubleConfigValueDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *DoubleConfigValueDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int DoubleConfigValueDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int DoubleConfigValueDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_maxValue
        FD_ISEDITABLE,    // FIELD_minValue
        FD_ISEDITABLE,    // FIELD_currentValue
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *DoubleConfigValueDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "maxValue",
        "minValue",
        "currentValue",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int DoubleConfigValueDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "maxValue") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "minValue") == 0) return base+1;
    if (fieldName[0] == 'c' && strcmp(fieldName, "currentValue") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *DoubleConfigValueDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",    // FIELD_maxValue
        "double",    // FIELD_minValue
        "double",    // FIELD_currentValue
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **DoubleConfigValueDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *DoubleConfigValueDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int DoubleConfigValueDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    DoubleConfigValue *pp = (DoubleConfigValue *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *DoubleConfigValueDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DoubleConfigValue *pp = (DoubleConfigValue *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DoubleConfigValueDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DoubleConfigValue *pp = (DoubleConfigValue *)object; (void)pp;
    switch (field) {
        case FIELD_maxValue: return double2string(pp->maxValue);
        case FIELD_minValue: return double2string(pp->minValue);
        case FIELD_currentValue: return double2string(pp->currentValue);
        default: return "";
    }
}

bool DoubleConfigValueDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    DoubleConfigValue *pp = (DoubleConfigValue *)object; (void)pp;
    switch (field) {
        case FIELD_maxValue: pp->maxValue = string2double(value); return true;
        case FIELD_minValue: pp->minValue = string2double(value); return true;
        case FIELD_currentValue: pp->currentValue = string2double(value); return true;
        default: return false;
    }
}

const char *DoubleConfigValueDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *DoubleConfigValueDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    DoubleConfigValue *pp = (DoubleConfigValue *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Config::Config()
{
}

Config::Config(const Config& other)
{
    copy(other);
}

Config::~Config()
{
}

Config& Config::operator=(const Config& other)
{
    if (this == &other) return *this;
    copy(other);
    return *this;
}

void Config::copy(const Config& other)
{
    this->heartbeatInterval = other.heartbeatInterval;
    this->missingHbAllowed = other.missingHbAllowed;
    this->probingRate = other.probingRate;
    this->maxRetransmit = other.maxRetransmit;
    this->ackTimeout = other.ackTimeout;
    this->ackRandomFactor = other.ackRandomFactor;
}

void Config::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->heartbeatInterval);
    doParsimPacking(b,this->missingHbAllowed);
    doParsimPacking(b,this->probingRate);
    doParsimPacking(b,this->maxRetransmit);
    doParsimPacking(b,this->ackTimeout);
    doParsimPacking(b,this->ackRandomFactor);
}

void Config::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->heartbeatInterval);
    doParsimUnpacking(b,this->missingHbAllowed);
    doParsimUnpacking(b,this->probingRate);
    doParsimUnpacking(b,this->maxRetransmit);
    doParsimUnpacking(b,this->ackTimeout);
    doParsimUnpacking(b,this->ackRandomFactor);
}

const IntConfigValue& Config::getHeartbeatInterval() const
{
    return this->heartbeatInterval;
}

void Config::setHeartbeatInterval(const IntConfigValue& heartbeatInterval)
{
    this->heartbeatInterval = heartbeatInterval;
}

const IntConfigValue& Config::getMissingHbAllowed() const
{
    return this->missingHbAllowed;
}

void Config::setMissingHbAllowed(const IntConfigValue& missingHbAllowed)
{
    this->missingHbAllowed = missingHbAllowed;
}

const IntConfigValue& Config::getProbingRate() const
{
    return this->probingRate;
}

void Config::setProbingRate(const IntConfigValue& probingRate)
{
    this->probingRate = probingRate;
}

const IntConfigValue& Config::getMaxRetransmit() const
{
    return this->maxRetransmit;
}

void Config::setMaxRetransmit(const IntConfigValue& maxRetransmit)
{
    this->maxRetransmit = maxRetransmit;
}

const DoubleConfigValue& Config::getAckTimeout() const
{
    return this->ackTimeout;
}

void Config::setAckTimeout(const DoubleConfigValue& ackTimeout)
{
    this->ackTimeout = ackTimeout;
}

const DoubleConfigValue& Config::getAckRandomFactor() const
{
    return this->ackRandomFactor;
}

void Config::setAckRandomFactor(const DoubleConfigValue& ackRandomFactor)
{
    this->ackRandomFactor = ackRandomFactor;
}

class ConfigDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_heartbeatInterval,
        FIELD_missingHbAllowed,
        FIELD_probingRate,
        FIELD_maxRetransmit,
        FIELD_ackTimeout,
        FIELD_ackRandomFactor,
    };
  public:
    ConfigDescriptor();
    virtual ~ConfigDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(ConfigDescriptor)

ConfigDescriptor::ConfigDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Config)), "")
{
    propertynames = nullptr;
}

ConfigDescriptor::~ConfigDescriptor()
{
    delete[] propertynames;
}

bool ConfigDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Config *>(obj)!=nullptr;
}

const char **ConfigDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ConfigDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ConfigDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int ConfigDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_heartbeatInterval
        FD_ISCOMPOUND,    // FIELD_missingHbAllowed
        FD_ISCOMPOUND,    // FIELD_probingRate
        FD_ISCOMPOUND,    // FIELD_maxRetransmit
        FD_ISCOMPOUND,    // FIELD_ackTimeout
        FD_ISCOMPOUND,    // FIELD_ackRandomFactor
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *ConfigDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "heartbeatInterval",
        "missingHbAllowed",
        "probingRate",
        "maxRetransmit",
        "ackTimeout",
        "ackRandomFactor",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int ConfigDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "heartbeatInterval") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "missingHbAllowed") == 0) return base+1;
    if (fieldName[0] == 'p' && strcmp(fieldName, "probingRate") == 0) return base+2;
    if (fieldName[0] == 'm' && strcmp(fieldName, "maxRetransmit") == 0) return base+3;
    if (fieldName[0] == 'a' && strcmp(fieldName, "ackTimeout") == 0) return base+4;
    if (fieldName[0] == 'a' && strcmp(fieldName, "ackRandomFactor") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ConfigDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::IntConfigValue",    // FIELD_heartbeatInterval
        "inet::IntConfigValue",    // FIELD_missingHbAllowed
        "inet::IntConfigValue",    // FIELD_probingRate
        "inet::IntConfigValue",    // FIELD_maxRetransmit
        "inet::DoubleConfigValue",    // FIELD_ackTimeout
        "inet::DoubleConfigValue",    // FIELD_ackRandomFactor
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **ConfigDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ConfigDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ConfigDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Config *pp = (Config *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ConfigDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Config *pp = (Config *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ConfigDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Config *pp = (Config *)object; (void)pp;
    switch (field) {
        case FIELD_heartbeatInterval: {std::stringstream out; out << pp->getHeartbeatInterval(); return out.str();}
        case FIELD_missingHbAllowed: {std::stringstream out; out << pp->getMissingHbAllowed(); return out.str();}
        case FIELD_probingRate: {std::stringstream out; out << pp->getProbingRate(); return out.str();}
        case FIELD_maxRetransmit: {std::stringstream out; out << pp->getMaxRetransmit(); return out.str();}
        case FIELD_ackTimeout: {std::stringstream out; out << pp->getAckTimeout(); return out.str();}
        case FIELD_ackRandomFactor: {std::stringstream out; out << pp->getAckRandomFactor(); return out.str();}
        default: return "";
    }
}

bool ConfigDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Config *pp = (Config *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *ConfigDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_heartbeatInterval: return omnetpp::opp_typename(typeid(IntConfigValue));
        case FIELD_missingHbAllowed: return omnetpp::opp_typename(typeid(IntConfigValue));
        case FIELD_probingRate: return omnetpp::opp_typename(typeid(IntConfigValue));
        case FIELD_maxRetransmit: return omnetpp::opp_typename(typeid(IntConfigValue));
        case FIELD_ackTimeout: return omnetpp::opp_typename(typeid(DoubleConfigValue));
        case FIELD_ackRandomFactor: return omnetpp::opp_typename(typeid(DoubleConfigValue));
        default: return nullptr;
    };
}

void *ConfigDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Config *pp = (Config *)object; (void)pp;
    switch (field) {
        case FIELD_heartbeatInterval: return toVoidPtr(&pp->getHeartbeatInterval()); break;
        case FIELD_missingHbAllowed: return toVoidPtr(&pp->getMissingHbAllowed()); break;
        case FIELD_probingRate: return toVoidPtr(&pp->getProbingRate()); break;
        case FIELD_maxRetransmit: return toVoidPtr(&pp->getMaxRetransmit()); break;
        case FIELD_ackTimeout: return toVoidPtr(&pp->getAckTimeout()); break;
        case FIELD_ackRandomFactor: return toVoidPtr(&pp->getAckRandomFactor()); break;
        default: return nullptr;
    }
}

SessionConfig::SessionConfig()
{
}

SessionConfig::SessionConfig(const SessionConfig& other)
{
    copy(other);
}

SessionConfig::~SessionConfig()
{
}

SessionConfig& SessionConfig::operator=(const SessionConfig& other)
{
    if (this == &other) return *this;
    copy(other);
    return *this;
}

void SessionConfig::copy(const SessionConfig& other)
{
    this->sid = other.sid;
    this->MitigatingConfig = other.MitigatingConfig;
    this->IdleConfig = other.IdleConfig;
}

void SessionConfig::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->sid);
    doParsimPacking(b,this->MitigatingConfig);
    doParsimPacking(b,this->IdleConfig);
}

void SessionConfig::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->sid);
    doParsimUnpacking(b,this->MitigatingConfig);
    doParsimUnpacking(b,this->IdleConfig);
}

int SessionConfig::getSid() const
{
    return this->sid;
}

void SessionConfig::setSid(int sid)
{
    this->sid = sid;
}

const Config& SessionConfig::getMitigatingConfig() const
{
    return this->MitigatingConfig;
}

void SessionConfig::setMitigatingConfig(const Config& MitigatingConfig)
{
    this->MitigatingConfig = MitigatingConfig;
}

const Config& SessionConfig::getIdleConfig() const
{
    return this->IdleConfig;
}

void SessionConfig::setIdleConfig(const Config& IdleConfig)
{
    this->IdleConfig = IdleConfig;
}

class SessionConfigDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_sid,
        FIELD_MitigatingConfig,
        FIELD_IdleConfig,
    };
  public:
    SessionConfigDescriptor();
    virtual ~SessionConfigDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(SessionConfigDescriptor)

SessionConfigDescriptor::SessionConfigDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SessionConfig)), "")
{
    propertynames = nullptr;
}

SessionConfigDescriptor::~SessionConfigDescriptor()
{
    delete[] propertynames;
}

bool SessionConfigDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SessionConfig *>(obj)!=nullptr;
}

const char **SessionConfigDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SessionConfigDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SessionConfigDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SessionConfigDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_sid
        FD_ISCOMPOUND,    // FIELD_MitigatingConfig
        FD_ISCOMPOUND,    // FIELD_IdleConfig
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *SessionConfigDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sid",
        "MitigatingConfig",
        "IdleConfig",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int SessionConfigDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "sid") == 0) return base+0;
    if (fieldName[0] == 'M' && strcmp(fieldName, "MitigatingConfig") == 0) return base+1;
    if (fieldName[0] == 'I' && strcmp(fieldName, "IdleConfig") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SessionConfigDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_sid
        "inet::Config",    // FIELD_MitigatingConfig
        "inet::Config",    // FIELD_IdleConfig
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **SessionConfigDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *SessionConfigDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int SessionConfigDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SessionConfig *pp = (SessionConfig *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SessionConfigDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SessionConfig *pp = (SessionConfig *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SessionConfigDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SessionConfig *pp = (SessionConfig *)object; (void)pp;
    switch (field) {
        case FIELD_sid: return long2string(pp->getSid());
        case FIELD_MitigatingConfig: {std::stringstream out; out << pp->getMitigatingConfig(); return out.str();}
        case FIELD_IdleConfig: {std::stringstream out; out << pp->getIdleConfig(); return out.str();}
        default: return "";
    }
}

bool SessionConfigDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SessionConfig *pp = (SessionConfig *)object; (void)pp;
    switch (field) {
        case FIELD_sid: pp->setSid(string2long(value)); return true;
        default: return false;
    }
}

const char *SessionConfigDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_MitigatingConfig: return omnetpp::opp_typename(typeid(Config));
        case FIELD_IdleConfig: return omnetpp::opp_typename(typeid(Config));
        default: return nullptr;
    };
}

void *SessionConfigDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SessionConfig *pp = (SessionConfig *)object; (void)pp;
    switch (field) {
        case FIELD_MitigatingConfig: return toVoidPtr(&pp->getMitigatingConfig()); break;
        case FIELD_IdleConfig: return toVoidPtr(&pp->getIdleConfig()); break;
        default: return nullptr;
    }
}

} // namespace inet

