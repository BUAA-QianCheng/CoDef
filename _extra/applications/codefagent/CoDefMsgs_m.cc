//
// Generated file, do not edit! Created by nedtool 5.6 from inet/_extra/applications/codefagent/CoDefMsgs.msg.
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
#include "CoDefMsgs_m.h"

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

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::RequestType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::RequestType"));
    e->insert(GET, "GET");
    e->insert(POST, "POST");
    e->insert(PUT, "PUT");
    e->insert(DEL, "DEL");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ResponseType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ResponseType"));
    e->insert(CREATED, "CREATED");
    e->insert(DELETED, "DELETED");
    e->insert(VALID, "VALID");
    e->insert(CHANGED, "CHANGED");
    e->insert(CONTENT, "CONTENT");
    e->insert(BAD_REQUEST, "BAD_REQUEST");
    e->insert(UNAUTHORIZED, "UNAUTHORIZED");
    e->insert(BAD_OPTION, "BAD_OPTION");
    e->insert(FORBIDDEN, "FORBIDDEN");
    e->insert(NOT_FOUND, "NOT_FOUND");
    e->insert(METHOD_NOT_ALLOWED, "METHOD_NOT_ALLOWED");
    e->insert(NOT_ACCEPTABLE, "NOT_ACCEPTABLE");
    e->insert(CONFLICT, "CONFLICT");
    e->insert(PRECONDITION_FAILED, "PRECONDITION_FAILED");
    e->insert(REQUEST_ENTITY_TOO_LARGE, "REQUEST_ENTITY_TOO_LARGE");
    e->insert(UNSUPPORTED_CONTENT_FORMAT, "UNSUPPORTED_CONTENT_FORMAT");
    e->insert(INTERNAL_SERVER_ERROR, "INTERNAL_SERVER_ERROR");
    e->insert(NOT_IMPLEMENTED, "NOT_IMPLEMENTED");
    e->insert(BAD_GATEWAY, "BAD_GATEWAY");
    e->insert(SERVICE_UNAVAILABLE, "SERVICE_UNAVAILABLE");
    e->insert(GATEWAY_TIMEOUT, "GATEWAY_TIMEOUT");
    e->insert(PROXYING_NOT_SUPPORTED, "PROXYING_NOT_SUPPORTED");
)

Register_Class(CoDefRequestHeader)

CoDefRequestHeader::CoDefRequestHeader() : ::inet::FieldsChunk()
{
}

CoDefRequestHeader::CoDefRequestHeader(const CoDefRequestHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

CoDefRequestHeader::~CoDefRequestHeader()
{
    delete [] this->uriPath;
}

CoDefRequestHeader& CoDefRequestHeader::operator=(const CoDefRequestHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void CoDefRequestHeader::copy(const CoDefRequestHeader& other)
{
    this->header = other.header;
    delete [] this->uriPath;
    this->uriPath = (other.uriPath_arraysize==0) ? nullptr : new omnetpp::opp_string[other.uriPath_arraysize];
    uriPath_arraysize = other.uriPath_arraysize;
    for (size_t i = 0; i < uriPath_arraysize; i++) {
        this->uriPath[i] = other.uriPath[i];
    }
}

void CoDefRequestHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->header);
    b->pack(uriPath_arraysize);
    doParsimArrayPacking(b,this->uriPath,uriPath_arraysize);
}

void CoDefRequestHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->header);
    delete [] this->uriPath;
    b->unpack(uriPath_arraysize);
    if (uriPath_arraysize == 0) {
        this->uriPath = nullptr;
    } else {
        this->uriPath = new omnetpp::opp_string[uriPath_arraysize];
        doParsimArrayUnpacking(b,this->uriPath,uriPath_arraysize);
    }
}

inet::RequestType CoDefRequestHeader::getHeader() const
{
    return this->header;
}

void CoDefRequestHeader::setHeader(inet::RequestType header)
{
    handleChange();
    this->header = header;
}

size_t CoDefRequestHeader::getUriPathArraySize() const
{
    return uriPath_arraysize;
}

const char * CoDefRequestHeader::getUriPath(size_t k) const
{
    if (k >= uriPath_arraysize) throw omnetpp::cRuntimeError("Array of size uriPath_arraysize indexed by %lu", (unsigned long)k);
    return this->uriPath[k].c_str();
}

void CoDefRequestHeader::setUriPathArraySize(size_t newSize)
{
    handleChange();
    omnetpp::opp_string *uriPath2 = (newSize==0) ? nullptr : new omnetpp::opp_string[newSize];
    size_t minSize = uriPath_arraysize < newSize ? uriPath_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        uriPath2[i] = this->uriPath[i];
    delete [] this->uriPath;
    this->uriPath = uriPath2;
    uriPath_arraysize = newSize;
}

void CoDefRequestHeader::setUriPath(size_t k, const char * uriPath)
{
    if (k >= uriPath_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->uriPath[k] = uriPath;
}

void CoDefRequestHeader::insertUriPath(size_t k, const char * uriPath)
{
    handleChange();
    if (k > uriPath_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = uriPath_arraysize + 1;
    omnetpp::opp_string *uriPath2 = new omnetpp::opp_string[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        uriPath2[i] = this->uriPath[i];
    uriPath2[k] = uriPath;
    for (i = k + 1; i < newSize; i++)
        uriPath2[i] = this->uriPath[i-1];
    delete [] this->uriPath;
    this->uriPath = uriPath2;
    uriPath_arraysize = newSize;
}

void CoDefRequestHeader::insertUriPath(const char * uriPath)
{
    insertUriPath(uriPath_arraysize, uriPath);
}

void CoDefRequestHeader::eraseUriPath(size_t k)
{
    if (k >= uriPath_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = uriPath_arraysize - 1;
    omnetpp::opp_string *uriPath2 = (newSize == 0) ? nullptr : new omnetpp::opp_string[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        uriPath2[i] = this->uriPath[i];
    for (i = k; i < newSize; i++)
        uriPath2[i] = this->uriPath[i+1];
    delete [] this->uriPath;
    this->uriPath = uriPath2;
    uriPath_arraysize = newSize;
}

class CoDefRequestHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_header,
        FIELD_uriPath,
    };
  public:
    CoDefRequestHeaderDescriptor();
    virtual ~CoDefRequestHeaderDescriptor();

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

Register_ClassDescriptor(CoDefRequestHeaderDescriptor)

CoDefRequestHeaderDescriptor::CoDefRequestHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::CoDefRequestHeader)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

CoDefRequestHeaderDescriptor::~CoDefRequestHeaderDescriptor()
{
    delete[] propertynames;
}

bool CoDefRequestHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CoDefRequestHeader *>(obj)!=nullptr;
}

const char **CoDefRequestHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *CoDefRequestHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int CoDefRequestHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int CoDefRequestHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_header
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_uriPath
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *CoDefRequestHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "header",
        "uriPath",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int CoDefRequestHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "header") == 0) return base+0;
    if (fieldName[0] == 'u' && strcmp(fieldName, "uriPath") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *CoDefRequestHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::RequestType",    // FIELD_header
        "string",    // FIELD_uriPath
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **CoDefRequestHeaderDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_header: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *CoDefRequestHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_header:
            if (!strcmp(propertyname, "enum")) return "inet::RequestType";
            return nullptr;
        default: return nullptr;
    }
}

int CoDefRequestHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    CoDefRequestHeader *pp = (CoDefRequestHeader *)object; (void)pp;
    switch (field) {
        case FIELD_uriPath: return pp->getUriPathArraySize();
        default: return 0;
    }
}

const char *CoDefRequestHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CoDefRequestHeader *pp = (CoDefRequestHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CoDefRequestHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CoDefRequestHeader *pp = (CoDefRequestHeader *)object; (void)pp;
    switch (field) {
        case FIELD_header: return enum2string(pp->getHeader(), "inet::RequestType");
        case FIELD_uriPath: return oppstring2string(pp->getUriPath(i));
        default: return "";
    }
}

bool CoDefRequestHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    CoDefRequestHeader *pp = (CoDefRequestHeader *)object; (void)pp;
    switch (field) {
        case FIELD_uriPath: pp->setUriPath(i,(value)); return true;
        default: return false;
    }
}

const char *CoDefRequestHeaderDescriptor::getFieldStructName(int field) const
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

void *CoDefRequestHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    CoDefRequestHeader *pp = (CoDefRequestHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(CoDefResponseHeader)

CoDefResponseHeader::CoDefResponseHeader() : ::inet::FieldsChunk()
{
}

CoDefResponseHeader::CoDefResponseHeader(const CoDefResponseHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

CoDefResponseHeader::~CoDefResponseHeader()
{
    delete [] this->uriPath;
}

CoDefResponseHeader& CoDefResponseHeader::operator=(const CoDefResponseHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void CoDefResponseHeader::copy(const CoDefResponseHeader& other)
{
    this->header = other.header;
    delete [] this->uriPath;
    this->uriPath = (other.uriPath_arraysize==0) ? nullptr : new omnetpp::opp_string[other.uriPath_arraysize];
    uriPath_arraysize = other.uriPath_arraysize;
    for (size_t i = 0; i < uriPath_arraysize; i++) {
        this->uriPath[i] = other.uriPath[i];
    }
}

void CoDefResponseHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->header);
    b->pack(uriPath_arraysize);
    doParsimArrayPacking(b,this->uriPath,uriPath_arraysize);
}

void CoDefResponseHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->header);
    delete [] this->uriPath;
    b->unpack(uriPath_arraysize);
    if (uriPath_arraysize == 0) {
        this->uriPath = nullptr;
    } else {
        this->uriPath = new omnetpp::opp_string[uriPath_arraysize];
        doParsimArrayUnpacking(b,this->uriPath,uriPath_arraysize);
    }
}

inet::ResponseType CoDefResponseHeader::getHeader() const
{
    return this->header;
}

void CoDefResponseHeader::setHeader(inet::ResponseType header)
{
    handleChange();
    this->header = header;
}

size_t CoDefResponseHeader::getUriPathArraySize() const
{
    return uriPath_arraysize;
}

const char * CoDefResponseHeader::getUriPath(size_t k) const
{
    if (k >= uriPath_arraysize) throw omnetpp::cRuntimeError("Array of size uriPath_arraysize indexed by %lu", (unsigned long)k);
    return this->uriPath[k].c_str();
}

void CoDefResponseHeader::setUriPathArraySize(size_t newSize)
{
    handleChange();
    omnetpp::opp_string *uriPath2 = (newSize==0) ? nullptr : new omnetpp::opp_string[newSize];
    size_t minSize = uriPath_arraysize < newSize ? uriPath_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        uriPath2[i] = this->uriPath[i];
    delete [] this->uriPath;
    this->uriPath = uriPath2;
    uriPath_arraysize = newSize;
}

void CoDefResponseHeader::setUriPath(size_t k, const char * uriPath)
{
    if (k >= uriPath_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->uriPath[k] = uriPath;
}

void CoDefResponseHeader::insertUriPath(size_t k, const char * uriPath)
{
    handleChange();
    if (k > uriPath_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = uriPath_arraysize + 1;
    omnetpp::opp_string *uriPath2 = new omnetpp::opp_string[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        uriPath2[i] = this->uriPath[i];
    uriPath2[k] = uriPath;
    for (i = k + 1; i < newSize; i++)
        uriPath2[i] = this->uriPath[i-1];
    delete [] this->uriPath;
    this->uriPath = uriPath2;
    uriPath_arraysize = newSize;
}

void CoDefResponseHeader::insertUriPath(const char * uriPath)
{
    insertUriPath(uriPath_arraysize, uriPath);
}

void CoDefResponseHeader::eraseUriPath(size_t k)
{
    if (k >= uriPath_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = uriPath_arraysize - 1;
    omnetpp::opp_string *uriPath2 = (newSize == 0) ? nullptr : new omnetpp::opp_string[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        uriPath2[i] = this->uriPath[i];
    for (i = k; i < newSize; i++)
        uriPath2[i] = this->uriPath[i+1];
    delete [] this->uriPath;
    this->uriPath = uriPath2;
    uriPath_arraysize = newSize;
}

class CoDefResponseHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_header,
        FIELD_uriPath,
    };
  public:
    CoDefResponseHeaderDescriptor();
    virtual ~CoDefResponseHeaderDescriptor();

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

Register_ClassDescriptor(CoDefResponseHeaderDescriptor)

CoDefResponseHeaderDescriptor::CoDefResponseHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::CoDefResponseHeader)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

CoDefResponseHeaderDescriptor::~CoDefResponseHeaderDescriptor()
{
    delete[] propertynames;
}

bool CoDefResponseHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CoDefResponseHeader *>(obj)!=nullptr;
}

const char **CoDefResponseHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *CoDefResponseHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int CoDefResponseHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int CoDefResponseHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_header
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_uriPath
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *CoDefResponseHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "header",
        "uriPath",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int CoDefResponseHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'h' && strcmp(fieldName, "header") == 0) return base+0;
    if (fieldName[0] == 'u' && strcmp(fieldName, "uriPath") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *CoDefResponseHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::ResponseType",    // FIELD_header
        "string",    // FIELD_uriPath
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **CoDefResponseHeaderDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_header: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *CoDefResponseHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_header:
            if (!strcmp(propertyname, "enum")) return "inet::ResponseType";
            return nullptr;
        default: return nullptr;
    }
}

int CoDefResponseHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    CoDefResponseHeader *pp = (CoDefResponseHeader *)object; (void)pp;
    switch (field) {
        case FIELD_uriPath: return pp->getUriPathArraySize();
        default: return 0;
    }
}

const char *CoDefResponseHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CoDefResponseHeader *pp = (CoDefResponseHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CoDefResponseHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CoDefResponseHeader *pp = (CoDefResponseHeader *)object; (void)pp;
    switch (field) {
        case FIELD_header: return enum2string(pp->getHeader(), "inet::ResponseType");
        case FIELD_uriPath: return oppstring2string(pp->getUriPath(i));
        default: return "";
    }
}

bool CoDefResponseHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    CoDefResponseHeader *pp = (CoDefResponseHeader *)object; (void)pp;
    switch (field) {
        case FIELD_uriPath: pp->setUriPath(i,(value)); return true;
        default: return false;
    }
}

const char *CoDefResponseHeaderDescriptor::getFieldStructName(int field) const
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

void *CoDefResponseHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    CoDefResponseHeader *pp = (CoDefResponseHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

