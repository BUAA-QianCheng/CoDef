//
// Generated file, do not edit! Created by nedtool 5.6 from inet/_extra/networklayer/FilterRule.msg.
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
#include "FilterRule_m.h"

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

Ipv4Match::Ipv4Match()
{
}

Ipv4Match::Ipv4Match(const Ipv4Match& other)
{
    copy(other);
}

Ipv4Match::~Ipv4Match()
{
}

Ipv4Match& Ipv4Match::operator=(const Ipv4Match& other)
{
    if (this == &other) return *this;
    copy(other);
    return *this;
}

void Ipv4Match::copy(const Ipv4Match& other)
{
    this->length = other.length;
    this->protocol = other.protocol;
    this->destNetwork = other.destNetwork;
    this->srcNetwork = other.srcNetwork;
    this->fragmentOp = other.fragmentOp;
    this->fragmentType = other.fragmentType;
}

void Ipv4Match::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->length);
    doParsimPacking(b,this->protocol);
    doParsimPacking(b,this->destNetwork);
    doParsimPacking(b,this->srcNetwork);
    doParsimPacking(b,this->fragmentOp);
    doParsimPacking(b,this->fragmentType);
}

void Ipv4Match::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->length);
    doParsimUnpacking(b,this->protocol);
    doParsimUnpacking(b,this->destNetwork);
    doParsimUnpacking(b,this->srcNetwork);
    doParsimUnpacking(b,this->fragmentOp);
    doParsimUnpacking(b,this->fragmentType);
}

uint16_t Ipv4Match::getLength() const
{
    return this->length;
}

void Ipv4Match::setLength(uint16_t length)
{
    this->length = length;
}

uint8_t Ipv4Match::getProtocol() const
{
    return this->protocol;
}

void Ipv4Match::setProtocol(uint8_t protocol)
{
    this->protocol = protocol;
}

const Ipv4Address& Ipv4Match::getDestNetwork() const
{
    return this->destNetwork;
}

void Ipv4Match::setDestNetwork(const Ipv4Address& destNetwork)
{
    this->destNetwork = destNetwork;
}

const Ipv4Address& Ipv4Match::getSrcNetwork() const
{
    return this->srcNetwork;
}

void Ipv4Match::setSrcNetwork(const Ipv4Address& srcNetwork)
{
    this->srcNetwork = srcNetwork;
}

uint8_t Ipv4Match::getFragmentOp() const
{
    return this->fragmentOp;
}

void Ipv4Match::setFragmentOp(uint8_t fragmentOp)
{
    this->fragmentOp = fragmentOp;
}

uint8_t Ipv4Match::getFragmentType() const
{
    return this->fragmentType;
}

void Ipv4Match::setFragmentType(uint8_t fragmentType)
{
    this->fragmentType = fragmentType;
}

class Ipv4MatchDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_length,
        FIELD_protocol,
        FIELD_destNetwork,
        FIELD_srcNetwork,
        FIELD_fragmentOp,
        FIELD_fragmentType,
    };
  public:
    Ipv4MatchDescriptor();
    virtual ~Ipv4MatchDescriptor();

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

Register_ClassDescriptor(Ipv4MatchDescriptor)

Ipv4MatchDescriptor::Ipv4MatchDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv4Match)), "")
{
    propertynames = nullptr;
}

Ipv4MatchDescriptor::~Ipv4MatchDescriptor()
{
    delete[] propertynames;
}

bool Ipv4MatchDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv4Match *>(obj)!=nullptr;
}

const char **Ipv4MatchDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv4MatchDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv4MatchDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int Ipv4MatchDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_length
        FD_ISEDITABLE,    // FIELD_protocol
        0,    // FIELD_destNetwork
        0,    // FIELD_srcNetwork
        FD_ISEDITABLE,    // FIELD_fragmentOp
        FD_ISEDITABLE,    // FIELD_fragmentType
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *Ipv4MatchDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "length",
        "protocol",
        "destNetwork",
        "srcNetwork",
        "fragmentOp",
        "fragmentType",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int Ipv4MatchDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "length") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "protocol") == 0) return base+1;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destNetwork") == 0) return base+2;
    if (fieldName[0] == 's' && strcmp(fieldName, "srcNetwork") == 0) return base+3;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fragmentOp") == 0) return base+4;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fragmentType") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv4MatchDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_length
        "uint8_t",    // FIELD_protocol
        "inet::Ipv4Address",    // FIELD_destNetwork
        "inet::Ipv4Address",    // FIELD_srcNetwork
        "uint8_t",    // FIELD_fragmentOp
        "uint8_t",    // FIELD_fragmentType
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv4MatchDescriptor::getFieldPropertyNames(int field) const
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

const char *Ipv4MatchDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ipv4MatchDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv4Match *pp = (Ipv4Match *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv4MatchDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv4Match *pp = (Ipv4Match *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv4MatchDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv4Match *pp = (Ipv4Match *)object; (void)pp;
    switch (field) {
        case FIELD_length: return ulong2string(pp->getLength());
        case FIELD_protocol: return ulong2string(pp->getProtocol());
        case FIELD_destNetwork: return pp->getDestNetwork().str();
        case FIELD_srcNetwork: return pp->getSrcNetwork().str();
        case FIELD_fragmentOp: return ulong2string(pp->getFragmentOp());
        case FIELD_fragmentType: return ulong2string(pp->getFragmentType());
        default: return "";
    }
}

bool Ipv4MatchDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv4Match *pp = (Ipv4Match *)object; (void)pp;
    switch (field) {
        case FIELD_length: pp->setLength(string2ulong(value)); return true;
        case FIELD_protocol: pp->setProtocol(string2ulong(value)); return true;
        case FIELD_fragmentOp: pp->setFragmentOp(string2ulong(value)); return true;
        case FIELD_fragmentType: pp->setFragmentType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ipv4MatchDescriptor::getFieldStructName(int field) const
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

void *Ipv4MatchDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv4Match *pp = (Ipv4Match *)object; (void)pp;
    switch (field) {
        case FIELD_destNetwork: return toVoidPtr(&pp->getDestNetwork()); break;
        case FIELD_srcNetwork: return toVoidPtr(&pp->getSrcNetwork()); break;
        default: return nullptr;
    }
}

Ipv6Match::Ipv6Match()
{
}

Ipv6Match::Ipv6Match(const Ipv6Match& other)
{
    copy(other);
}

Ipv6Match::~Ipv6Match()
{
}

Ipv6Match& Ipv6Match::operator=(const Ipv6Match& other)
{
    if (this == &other) return *this;
    copy(other);
    return *this;
}

void Ipv6Match::copy(const Ipv6Match& other)
{
    this->length = other.length;
    this->protocol = other.protocol;
    this->destNetwork = other.destNetwork;
    this->srcNetwork = other.srcNetwork;
    this->fragmentOp = other.fragmentOp;
    this->fragmentType = other.fragmentType;
}

void Ipv6Match::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->length);
    doParsimPacking(b,this->protocol);
    doParsimPacking(b,this->destNetwork);
    doParsimPacking(b,this->srcNetwork);
    doParsimPacking(b,this->fragmentOp);
    doParsimPacking(b,this->fragmentType);
}

void Ipv6Match::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->length);
    doParsimUnpacking(b,this->protocol);
    doParsimUnpacking(b,this->destNetwork);
    doParsimUnpacking(b,this->srcNetwork);
    doParsimUnpacking(b,this->fragmentOp);
    doParsimUnpacking(b,this->fragmentType);
}

uint16_t Ipv6Match::getLength() const
{
    return this->length;
}

void Ipv6Match::setLength(uint16_t length)
{
    this->length = length;
}

uint8_t Ipv6Match::getProtocol() const
{
    return this->protocol;
}

void Ipv6Match::setProtocol(uint8_t protocol)
{
    this->protocol = protocol;
}

const Ipv6Address& Ipv6Match::getDestNetwork() const
{
    return this->destNetwork;
}

void Ipv6Match::setDestNetwork(const Ipv6Address& destNetwork)
{
    this->destNetwork = destNetwork;
}

const Ipv6Address& Ipv6Match::getSrcNetwork() const
{
    return this->srcNetwork;
}

void Ipv6Match::setSrcNetwork(const Ipv6Address& srcNetwork)
{
    this->srcNetwork = srcNetwork;
}

uint8_t Ipv6Match::getFragmentOp() const
{
    return this->fragmentOp;
}

void Ipv6Match::setFragmentOp(uint8_t fragmentOp)
{
    this->fragmentOp = fragmentOp;
}

uint8_t Ipv6Match::getFragmentType() const
{
    return this->fragmentType;
}

void Ipv6Match::setFragmentType(uint8_t fragmentType)
{
    this->fragmentType = fragmentType;
}

class Ipv6MatchDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_length,
        FIELD_protocol,
        FIELD_destNetwork,
        FIELD_srcNetwork,
        FIELD_fragmentOp,
        FIELD_fragmentType,
    };
  public:
    Ipv6MatchDescriptor();
    virtual ~Ipv6MatchDescriptor();

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

Register_ClassDescriptor(Ipv6MatchDescriptor)

Ipv6MatchDescriptor::Ipv6MatchDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ipv6Match)), "")
{
    propertynames = nullptr;
}

Ipv6MatchDescriptor::~Ipv6MatchDescriptor()
{
    delete[] propertynames;
}

bool Ipv6MatchDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ipv6Match *>(obj)!=nullptr;
}

const char **Ipv6MatchDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ipv6MatchDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ipv6MatchDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int Ipv6MatchDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_length
        FD_ISEDITABLE,    // FIELD_protocol
        0,    // FIELD_destNetwork
        0,    // FIELD_srcNetwork
        FD_ISEDITABLE,    // FIELD_fragmentOp
        FD_ISEDITABLE,    // FIELD_fragmentType
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *Ipv6MatchDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "length",
        "protocol",
        "destNetwork",
        "srcNetwork",
        "fragmentOp",
        "fragmentType",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int Ipv6MatchDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "length") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "protocol") == 0) return base+1;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destNetwork") == 0) return base+2;
    if (fieldName[0] == 's' && strcmp(fieldName, "srcNetwork") == 0) return base+3;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fragmentOp") == 0) return base+4;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fragmentType") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ipv6MatchDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_length
        "uint8_t",    // FIELD_protocol
        "inet::Ipv6Address",    // FIELD_destNetwork
        "inet::Ipv6Address",    // FIELD_srcNetwork
        "uint8_t",    // FIELD_fragmentOp
        "uint8_t",    // FIELD_fragmentType
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **Ipv6MatchDescriptor::getFieldPropertyNames(int field) const
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

const char *Ipv6MatchDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ipv6MatchDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ipv6Match *pp = (Ipv6Match *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ipv6MatchDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6Match *pp = (Ipv6Match *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ipv6MatchDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ipv6Match *pp = (Ipv6Match *)object; (void)pp;
    switch (field) {
        case FIELD_length: return ulong2string(pp->getLength());
        case FIELD_protocol: return ulong2string(pp->getProtocol());
        case FIELD_destNetwork: return pp->getDestNetwork().str();
        case FIELD_srcNetwork: return pp->getSrcNetwork().str();
        case FIELD_fragmentOp: return ulong2string(pp->getFragmentOp());
        case FIELD_fragmentType: return ulong2string(pp->getFragmentType());
        default: return "";
    }
}

bool Ipv6MatchDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ipv6Match *pp = (Ipv6Match *)object; (void)pp;
    switch (field) {
        case FIELD_length: pp->setLength(string2ulong(value)); return true;
        case FIELD_protocol: pp->setProtocol(string2ulong(value)); return true;
        case FIELD_fragmentOp: pp->setFragmentOp(string2ulong(value)); return true;
        case FIELD_fragmentType: pp->setFragmentType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ipv6MatchDescriptor::getFieldStructName(int field) const
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

void *Ipv6MatchDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ipv6Match *pp = (Ipv6Match *)object; (void)pp;
    switch (field) {
        case FIELD_destNetwork: return toVoidPtr(&pp->getDestNetwork()); break;
        case FIELD_srcNetwork: return toVoidPtr(&pp->getSrcNetwork()); break;
        default: return nullptr;
    }
}

TcpMatch::TcpMatch()
{
}

TcpMatch::TcpMatch(const TcpMatch& other)
{
    copy(other);
}

TcpMatch::~TcpMatch()
{
}

TcpMatch& TcpMatch::operator=(const TcpMatch& other)
{
    if (this == &other) return *this;
    copy(other);
    return *this;
}

void TcpMatch::copy(const TcpMatch& other)
{
    this->op = other.op;
    this->bitmask = other.bitmask;
    this->srcPortRange = other.srcPortRange;
    this->destPortRange = other.destPortRange;
}

void TcpMatch::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->op);
    doParsimPacking(b,this->bitmask);
    doParsimPacking(b,this->srcPortRange);
    doParsimPacking(b,this->destPortRange);
}

void TcpMatch::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->op);
    doParsimUnpacking(b,this->bitmask);
    doParsimUnpacking(b,this->srcPortRange);
    doParsimUnpacking(b,this->destPortRange);
}

uint8_t TcpMatch::getOp() const
{
    return this->op;
}

void TcpMatch::setOp(uint8_t op)
{
    this->op = op;
}

uint16_t TcpMatch::getBitmask() const
{
    return this->bitmask;
}

void TcpMatch::setBitmask(uint16_t bitmask)
{
    this->bitmask = bitmask;
}

const PortRange& TcpMatch::getSrcPortRange() const
{
    return this->srcPortRange;
}

void TcpMatch::setSrcPortRange(const PortRange& srcPortRange)
{
    this->srcPortRange = srcPortRange;
}

const PortRange& TcpMatch::getDestPortRange() const
{
    return this->destPortRange;
}

void TcpMatch::setDestPortRange(const PortRange& destPortRange)
{
    this->destPortRange = destPortRange;
}

class TcpMatchDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_op,
        FIELD_bitmask,
        FIELD_srcPortRange,
        FIELD_destPortRange,
    };
  public:
    TcpMatchDescriptor();
    virtual ~TcpMatchDescriptor();

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

Register_ClassDescriptor(TcpMatchDescriptor)

TcpMatchDescriptor::TcpMatchDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::TcpMatch)), "")
{
    propertynames = nullptr;
}

TcpMatchDescriptor::~TcpMatchDescriptor()
{
    delete[] propertynames;
}

bool TcpMatchDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TcpMatch *>(obj)!=nullptr;
}

const char **TcpMatchDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TcpMatchDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TcpMatchDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int TcpMatchDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_op
        FD_ISEDITABLE,    // FIELD_bitmask
        FD_ISCOMPOUND,    // FIELD_srcPortRange
        FD_ISCOMPOUND,    // FIELD_destPortRange
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *TcpMatchDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "op",
        "bitmask",
        "srcPortRange",
        "destPortRange",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int TcpMatchDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "op") == 0) return base+0;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bitmask") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "srcPortRange") == 0) return base+2;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destPortRange") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TcpMatchDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_op
        "uint16_t",    // FIELD_bitmask
        "PortRange",    // FIELD_srcPortRange
        "PortRange",    // FIELD_destPortRange
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **TcpMatchDescriptor::getFieldPropertyNames(int field) const
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

const char *TcpMatchDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TcpMatchDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TcpMatch *pp = (TcpMatch *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TcpMatchDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpMatch *pp = (TcpMatch *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TcpMatchDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TcpMatch *pp = (TcpMatch *)object; (void)pp;
    switch (field) {
        case FIELD_op: return ulong2string(pp->getOp());
        case FIELD_bitmask: return ulong2string(pp->getBitmask());
        case FIELD_srcPortRange: {std::stringstream out; out << pp->getSrcPortRange(); return out.str();}
        case FIELD_destPortRange: {std::stringstream out; out << pp->getDestPortRange(); return out.str();}
        default: return "";
    }
}

bool TcpMatchDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TcpMatch *pp = (TcpMatch *)object; (void)pp;
    switch (field) {
        case FIELD_op: pp->setOp(string2ulong(value)); return true;
        case FIELD_bitmask: pp->setBitmask(string2ulong(value)); return true;
        default: return false;
    }
}

const char *TcpMatchDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_srcPortRange: return omnetpp::opp_typename(typeid(PortRange));
        case FIELD_destPortRange: return omnetpp::opp_typename(typeid(PortRange));
        default: return nullptr;
    };
}

void *TcpMatchDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TcpMatch *pp = (TcpMatch *)object; (void)pp;
    switch (field) {
        case FIELD_srcPortRange: return toVoidPtr(&pp->getSrcPortRange()); break;
        case FIELD_destPortRange: return toVoidPtr(&pp->getDestPortRange()); break;
        default: return nullptr;
    }
}

UdpMatch::UdpMatch()
{
}

UdpMatch::UdpMatch(const UdpMatch& other)
{
    copy(other);
}

UdpMatch::~UdpMatch()
{
}

UdpMatch& UdpMatch::operator=(const UdpMatch& other)
{
    if (this == &other) return *this;
    copy(other);
    return *this;
}

void UdpMatch::copy(const UdpMatch& other)
{
    this->length = other.length;
    this->srcPortRange = other.srcPortRange;
    this->destPortRange = other.destPortRange;
}

void UdpMatch::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->length);
    doParsimPacking(b,this->srcPortRange);
    doParsimPacking(b,this->destPortRange);
}

void UdpMatch::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->length);
    doParsimUnpacking(b,this->srcPortRange);
    doParsimUnpacking(b,this->destPortRange);
}

uint16_t UdpMatch::getLength() const
{
    return this->length;
}

void UdpMatch::setLength(uint16_t length)
{
    this->length = length;
}

const PortRange& UdpMatch::getSrcPortRange() const
{
    return this->srcPortRange;
}

void UdpMatch::setSrcPortRange(const PortRange& srcPortRange)
{
    this->srcPortRange = srcPortRange;
}

const PortRange& UdpMatch::getDestPortRange() const
{
    return this->destPortRange;
}

void UdpMatch::setDestPortRange(const PortRange& destPortRange)
{
    this->destPortRange = destPortRange;
}

class UdpMatchDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_length,
        FIELD_srcPortRange,
        FIELD_destPortRange,
    };
  public:
    UdpMatchDescriptor();
    virtual ~UdpMatchDescriptor();

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

Register_ClassDescriptor(UdpMatchDescriptor)

UdpMatchDescriptor::UdpMatchDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::UdpMatch)), "")
{
    propertynames = nullptr;
}

UdpMatchDescriptor::~UdpMatchDescriptor()
{
    delete[] propertynames;
}

bool UdpMatchDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UdpMatch *>(obj)!=nullptr;
}

const char **UdpMatchDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UdpMatchDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UdpMatchDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int UdpMatchDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_length
        FD_ISCOMPOUND,    // FIELD_srcPortRange
        FD_ISCOMPOUND,    // FIELD_destPortRange
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *UdpMatchDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "length",
        "srcPortRange",
        "destPortRange",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int UdpMatchDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "length") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "srcPortRange") == 0) return base+1;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destPortRange") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UdpMatchDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_length
        "PortRange",    // FIELD_srcPortRange
        "PortRange",    // FIELD_destPortRange
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **UdpMatchDescriptor::getFieldPropertyNames(int field) const
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

const char *UdpMatchDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UdpMatchDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UdpMatch *pp = (UdpMatch *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UdpMatchDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpMatch *pp = (UdpMatch *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UdpMatchDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UdpMatch *pp = (UdpMatch *)object; (void)pp;
    switch (field) {
        case FIELD_length: return ulong2string(pp->getLength());
        case FIELD_srcPortRange: {std::stringstream out; out << pp->getSrcPortRange(); return out.str();}
        case FIELD_destPortRange: {std::stringstream out; out << pp->getDestPortRange(); return out.str();}
        default: return "";
    }
}

bool UdpMatchDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UdpMatch *pp = (UdpMatch *)object; (void)pp;
    switch (field) {
        case FIELD_length: pp->setLength(string2ulong(value)); return true;
        default: return false;
    }
}

const char *UdpMatchDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_srcPortRange: return omnetpp::opp_typename(typeid(PortRange));
        case FIELD_destPortRange: return omnetpp::opp_typename(typeid(PortRange));
        default: return nullptr;
    };
}

void *UdpMatchDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UdpMatch *pp = (UdpMatch *)object; (void)pp;
    switch (field) {
        case FIELD_srcPortRange: return toVoidPtr(&pp->getSrcPortRange()); break;
        case FIELD_destPortRange: return toVoidPtr(&pp->getDestPortRange()); break;
        default: return nullptr;
    }
}

IcmpMatch::IcmpMatch()
{
}

IcmpMatch::IcmpMatch(const IcmpMatch& other)
{
    copy(other);
}

IcmpMatch::~IcmpMatch()
{
}

IcmpMatch& IcmpMatch::operator=(const IcmpMatch& other)
{
    if (this == &other) return *this;
    copy(other);
    return *this;
}

void IcmpMatch::copy(const IcmpMatch& other)
{
    this->type = other.type;
    this->code = other.code;
}

void IcmpMatch::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->code);
}

void IcmpMatch::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->code);
}

int8_t IcmpMatch::getType() const
{
    return this->type;
}

void IcmpMatch::setType(int8_t type)
{
    this->type = type;
}

int8_t IcmpMatch::getCode() const
{
    return this->code;
}

void IcmpMatch::setCode(int8_t code)
{
    this->code = code;
}

class IcmpMatchDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_type,
        FIELD_code,
    };
  public:
    IcmpMatchDescriptor();
    virtual ~IcmpMatchDescriptor();

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

Register_ClassDescriptor(IcmpMatchDescriptor)

IcmpMatchDescriptor::IcmpMatchDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::IcmpMatch)), "")
{
    propertynames = nullptr;
}

IcmpMatchDescriptor::~IcmpMatchDescriptor()
{
    delete[] propertynames;
}

bool IcmpMatchDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IcmpMatch *>(obj)!=nullptr;
}

const char **IcmpMatchDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IcmpMatchDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IcmpMatchDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int IcmpMatchDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_code
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *IcmpMatchDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "code",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int IcmpMatchDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+0;
    if (fieldName[0] == 'c' && strcmp(fieldName, "code") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IcmpMatchDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int8_t",    // FIELD_type
        "int8_t",    // FIELD_code
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **IcmpMatchDescriptor::getFieldPropertyNames(int field) const
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

const char *IcmpMatchDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IcmpMatchDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IcmpMatch *pp = (IcmpMatch *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IcmpMatchDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IcmpMatch *pp = (IcmpMatch *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IcmpMatchDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IcmpMatch *pp = (IcmpMatch *)object; (void)pp;
    switch (field) {
        case FIELD_type: return long2string(pp->getType());
        case FIELD_code: return long2string(pp->getCode());
        default: return "";
    }
}

bool IcmpMatchDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IcmpMatch *pp = (IcmpMatch *)object; (void)pp;
    switch (field) {
        case FIELD_type: pp->setType(string2long(value)); return true;
        case FIELD_code: pp->setCode(string2long(value)); return true;
        default: return false;
    }
}

const char *IcmpMatchDescriptor::getFieldStructName(int field) const
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

void *IcmpMatchDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IcmpMatch *pp = (IcmpMatch *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Matches::Matches()
{
}

Matches::Matches(const Matches& other)
{
    copy(other);
}

Matches::~Matches()
{
}

Matches& Matches::operator=(const Matches& other)
{
    if (this == &other) return *this;
    copy(other);
    return *this;
}

void Matches::copy(const Matches& other)
{
    this->ipv4 = other.ipv4;
    this->ipv6 = other.ipv6;
    this->tcp = other.tcp;
    this->udp = other.udp;
    this->icmp = other.icmp;
}

void Matches::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->ipv4);
    doParsimPacking(b,this->ipv6);
    doParsimPacking(b,this->tcp);
    doParsimPacking(b,this->udp);
    doParsimPacking(b,this->icmp);
}

void Matches::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->ipv4);
    doParsimUnpacking(b,this->ipv6);
    doParsimUnpacking(b,this->tcp);
    doParsimUnpacking(b,this->udp);
    doParsimUnpacking(b,this->icmp);
}

const Ipv4Match& Matches::getIpv4() const
{
    return this->ipv4;
}

void Matches::setIpv4(const Ipv4Match& ipv4)
{
    this->ipv4 = ipv4;
}

const Ipv6Match& Matches::getIpv6() const
{
    return this->ipv6;
}

void Matches::setIpv6(const Ipv6Match& ipv6)
{
    this->ipv6 = ipv6;
}

const TcpMatch& Matches::getTcp() const
{
    return this->tcp;
}

void Matches::setTcp(const TcpMatch& tcp)
{
    this->tcp = tcp;
}

const UdpMatch& Matches::getUdp() const
{
    return this->udp;
}

void Matches::setUdp(const UdpMatch& udp)
{
    this->udp = udp;
}

const IcmpMatch& Matches::getIcmp() const
{
    return this->icmp;
}

void Matches::setIcmp(const IcmpMatch& icmp)
{
    this->icmp = icmp;
}

class MatchesDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_ipv4,
        FIELD_ipv6,
        FIELD_tcp,
        FIELD_udp,
        FIELD_icmp,
    };
  public:
    MatchesDescriptor();
    virtual ~MatchesDescriptor();

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

Register_ClassDescriptor(MatchesDescriptor)

MatchesDescriptor::MatchesDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Matches)), "")
{
    propertynames = nullptr;
}

MatchesDescriptor::~MatchesDescriptor()
{
    delete[] propertynames;
}

bool MatchesDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Matches *>(obj)!=nullptr;
}

const char **MatchesDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MatchesDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MatchesDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int MatchesDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_ipv4
        FD_ISCOMPOUND,    // FIELD_ipv6
        FD_ISCOMPOUND,    // FIELD_tcp
        FD_ISCOMPOUND,    // FIELD_udp
        FD_ISCOMPOUND,    // FIELD_icmp
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *MatchesDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ipv4",
        "ipv6",
        "tcp",
        "udp",
        "icmp",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int MatchesDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "ipv4") == 0) return base+0;
    if (fieldName[0] == 'i' && strcmp(fieldName, "ipv6") == 0) return base+1;
    if (fieldName[0] == 't' && strcmp(fieldName, "tcp") == 0) return base+2;
    if (fieldName[0] == 'u' && strcmp(fieldName, "udp") == 0) return base+3;
    if (fieldName[0] == 'i' && strcmp(fieldName, "icmp") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MatchesDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Match",    // FIELD_ipv4
        "inet::Ipv6Match",    // FIELD_ipv6
        "inet::TcpMatch",    // FIELD_tcp
        "inet::UdpMatch",    // FIELD_udp
        "inet::IcmpMatch",    // FIELD_icmp
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **MatchesDescriptor::getFieldPropertyNames(int field) const
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

const char *MatchesDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int MatchesDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Matches *pp = (Matches *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MatchesDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Matches *pp = (Matches *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MatchesDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Matches *pp = (Matches *)object; (void)pp;
    switch (field) {
        case FIELD_ipv4: {std::stringstream out; out << pp->getIpv4(); return out.str();}
        case FIELD_ipv6: {std::stringstream out; out << pp->getIpv6(); return out.str();}
        case FIELD_tcp: {std::stringstream out; out << pp->getTcp(); return out.str();}
        case FIELD_udp: {std::stringstream out; out << pp->getUdp(); return out.str();}
        case FIELD_icmp: {std::stringstream out; out << pp->getIcmp(); return out.str();}
        default: return "";
    }
}

bool MatchesDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Matches *pp = (Matches *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *MatchesDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_ipv4: return omnetpp::opp_typename(typeid(Ipv4Match));
        case FIELD_ipv6: return omnetpp::opp_typename(typeid(Ipv6Match));
        case FIELD_tcp: return omnetpp::opp_typename(typeid(TcpMatch));
        case FIELD_udp: return omnetpp::opp_typename(typeid(UdpMatch));
        case FIELD_icmp: return omnetpp::opp_typename(typeid(IcmpMatch));
        default: return nullptr;
    };
}

void *MatchesDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Matches *pp = (Matches *)object; (void)pp;
    switch (field) {
        case FIELD_ipv4: return toVoidPtr(&pp->getIpv4()); break;
        case FIELD_ipv6: return toVoidPtr(&pp->getIpv6()); break;
        case FIELD_tcp: return toVoidPtr(&pp->getTcp()); break;
        case FIELD_udp: return toVoidPtr(&pp->getUdp()); break;
        case FIELD_icmp: return toVoidPtr(&pp->getIcmp()); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ForwardingActions");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ForwardingActions"));
    e->insert(MATCH, "MATCH");
    e->insert(ACCEPT, "ACCEPT");
    e->insert(DROP, "DROP");
    e->insert(RATE_LIMIT, "RATE_LIMIT");
)

Action::Action()
{
}

Action::Action(const Action& other)
{
    copy(other);
}

Action::~Action()
{
}

Action& Action::operator=(const Action& other)
{
    if (this == &other) return *this;
    copy(other);
    return *this;
}

void Action::copy(const Action& other)
{
    this->forwarding = other.forwarding;
    this->rateLimit = other.rateLimit;
}

void Action::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->forwarding);
    doParsimPacking(b,this->rateLimit);
}

void Action::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->forwarding);
    doParsimUnpacking(b,this->rateLimit);
}

inet::ForwardingActions Action::getForwarding() const
{
    return this->forwarding;
}

void Action::setForwarding(inet::ForwardingActions forwarding)
{
    this->forwarding = forwarding;
}

double Action::getRateLimit() const
{
    return this->rateLimit;
}

void Action::setRateLimit(double rateLimit)
{
    this->rateLimit = rateLimit;
}

class ActionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_forwarding,
        FIELD_rateLimit,
    };
  public:
    ActionDescriptor();
    virtual ~ActionDescriptor();

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

Register_ClassDescriptor(ActionDescriptor)

ActionDescriptor::ActionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Action)), "")
{
    propertynames = nullptr;
}

ActionDescriptor::~ActionDescriptor()
{
    delete[] propertynames;
}

bool ActionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Action *>(obj)!=nullptr;
}

const char **ActionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ActionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ActionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int ActionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_forwarding
        FD_ISEDITABLE,    // FIELD_rateLimit
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *ActionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "forwarding",
        "rateLimit",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int ActionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'f' && strcmp(fieldName, "forwarding") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rateLimit") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ActionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ForwardingActions",    // FIELD_forwarding
        "double",    // FIELD_rateLimit
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **ActionDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_forwarding: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *ActionDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_forwarding:
            if (!strcmp(propertyname, "enum")) return "inet::ForwardingActions";
            return nullptr;
        default: return nullptr;
    }
}

int ActionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Action *pp = (Action *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ActionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Action *pp = (Action *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ActionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Action *pp = (Action *)object; (void)pp;
    switch (field) {
        case FIELD_forwarding: return enum2string(pp->getForwarding(), "inet::ForwardingActions");
        case FIELD_rateLimit: return double2string(pp->getRateLimit());
        default: return "";
    }
}

bool ActionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Action *pp = (Action *)object; (void)pp;
    switch (field) {
        case FIELD_rateLimit: pp->setRateLimit(string2double(value)); return true;
        default: return false;
    }
}

const char *ActionDescriptor::getFieldStructName(int field) const
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

void *ActionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Action *pp = (Action *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

