//
// Generated file, do not edit! Created by nedtool 5.6 from inet/_extra/applications/codefagent/CoDefMitigation.msg.
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
#include "CoDefMitigation_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::MitigationStatus");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::MitigationStatus"));
    e->insert(SETUP, "SETUP");
    e->insert(MITIGATED, "MITIGATED");
    e->insert(ATTACK_STOPPED, "ATTACK_STOPPED");
    e->insert(CAPABILITY_EXCEEDED, "CAPABILITY_EXCEEDED");
    e->insert(TERMINATING, "TERMINATING");
    e->insert(TERMINATED, "TERMINATED");
    e->insert(OVERLAPING, "OVERLAPING");
    e->insert(STANGING_BY, "STANGING_BY");
)

Register_Class(MitigationTarget)

MitigationTarget::MitigationTarget() : ::inet::FieldsChunk()
{
}

MitigationTarget::MitigationTarget(const MitigationTarget& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

MitigationTarget::~MitigationTarget()
{
    delete [] this->targetPrefix;
    delete [] this->portRange;
    delete [] this->targetProtocol;
    delete [] this->targetFqdn;
    delete [] this->targetUri;
}

MitigationTarget& MitigationTarget::operator=(const MitigationTarget& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void MitigationTarget::copy(const MitigationTarget& other)
{
    delete [] this->targetPrefix;
    this->targetPrefix = (other.targetPrefix_arraysize==0) ? nullptr : new Ipv4Address[other.targetPrefix_arraysize];
    targetPrefix_arraysize = other.targetPrefix_arraysize;
    for (size_t i = 0; i < targetPrefix_arraysize; i++) {
        this->targetPrefix[i] = other.targetPrefix[i];
    }
    delete [] this->portRange;
    this->portRange = (other.portRange_arraysize==0) ? nullptr : new PortRange[other.portRange_arraysize];
    portRange_arraysize = other.portRange_arraysize;
    for (size_t i = 0; i < portRange_arraysize; i++) {
        this->portRange[i] = other.portRange[i];
    }
    delete [] this->targetProtocol;
    this->targetProtocol = (other.targetProtocol_arraysize==0) ? nullptr : new uint8_t[other.targetProtocol_arraysize];
    targetProtocol_arraysize = other.targetProtocol_arraysize;
    for (size_t i = 0; i < targetProtocol_arraysize; i++) {
        this->targetProtocol[i] = other.targetProtocol[i];
    }
    delete [] this->targetFqdn;
    this->targetFqdn = (other.targetFqdn_arraysize==0) ? nullptr : new omnetpp::opp_string[other.targetFqdn_arraysize];
    targetFqdn_arraysize = other.targetFqdn_arraysize;
    for (size_t i = 0; i < targetFqdn_arraysize; i++) {
        this->targetFqdn[i] = other.targetFqdn[i];
    }
    delete [] this->targetUri;
    this->targetUri = (other.targetUri_arraysize==0) ? nullptr : new omnetpp::opp_string[other.targetUri_arraysize];
    targetUri_arraysize = other.targetUri_arraysize;
    for (size_t i = 0; i < targetUri_arraysize; i++) {
        this->targetUri[i] = other.targetUri[i];
    }
    this->aliasName = other.aliasName;
}

void MitigationTarget::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    b->pack(targetPrefix_arraysize);
    doParsimArrayPacking(b,this->targetPrefix,targetPrefix_arraysize);
    b->pack(portRange_arraysize);
    doParsimArrayPacking(b,this->portRange,portRange_arraysize);
    b->pack(targetProtocol_arraysize);
    doParsimArrayPacking(b,this->targetProtocol,targetProtocol_arraysize);
    b->pack(targetFqdn_arraysize);
    doParsimArrayPacking(b,this->targetFqdn,targetFqdn_arraysize);
    b->pack(targetUri_arraysize);
    doParsimArrayPacking(b,this->targetUri,targetUri_arraysize);
    doParsimPacking(b,this->aliasName);
}

void MitigationTarget::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    delete [] this->targetPrefix;
    b->unpack(targetPrefix_arraysize);
    if (targetPrefix_arraysize == 0) {
        this->targetPrefix = nullptr;
    } else {
        this->targetPrefix = new Ipv4Address[targetPrefix_arraysize];
        doParsimArrayUnpacking(b,this->targetPrefix,targetPrefix_arraysize);
    }
    delete [] this->portRange;
    b->unpack(portRange_arraysize);
    if (portRange_arraysize == 0) {
        this->portRange = nullptr;
    } else {
        this->portRange = new PortRange[portRange_arraysize];
        doParsimArrayUnpacking(b,this->portRange,portRange_arraysize);
    }
    delete [] this->targetProtocol;
    b->unpack(targetProtocol_arraysize);
    if (targetProtocol_arraysize == 0) {
        this->targetProtocol = nullptr;
    } else {
        this->targetProtocol = new uint8_t[targetProtocol_arraysize];
        doParsimArrayUnpacking(b,this->targetProtocol,targetProtocol_arraysize);
    }
    delete [] this->targetFqdn;
    b->unpack(targetFqdn_arraysize);
    if (targetFqdn_arraysize == 0) {
        this->targetFqdn = nullptr;
    } else {
        this->targetFqdn = new omnetpp::opp_string[targetFqdn_arraysize];
        doParsimArrayUnpacking(b,this->targetFqdn,targetFqdn_arraysize);
    }
    delete [] this->targetUri;
    b->unpack(targetUri_arraysize);
    if (targetUri_arraysize == 0) {
        this->targetUri = nullptr;
    } else {
        this->targetUri = new omnetpp::opp_string[targetUri_arraysize];
        doParsimArrayUnpacking(b,this->targetUri,targetUri_arraysize);
    }
    doParsimUnpacking(b,this->aliasName);
}

size_t MitigationTarget::getTargetPrefixArraySize() const
{
    return targetPrefix_arraysize;
}

const Ipv4Address& MitigationTarget::getTargetPrefix(size_t k) const
{
    if (k >= targetPrefix_arraysize) throw omnetpp::cRuntimeError("Array of size targetPrefix_arraysize indexed by %lu", (unsigned long)k);
    return this->targetPrefix[k];
}

void MitigationTarget::setTargetPrefixArraySize(size_t newSize)
{
    handleChange();
    Ipv4Address *targetPrefix2 = (newSize==0) ? nullptr : new Ipv4Address[newSize];
    size_t minSize = targetPrefix_arraysize < newSize ? targetPrefix_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        targetPrefix2[i] = this->targetPrefix[i];
    delete [] this->targetPrefix;
    this->targetPrefix = targetPrefix2;
    targetPrefix_arraysize = newSize;
}

void MitigationTarget::setTargetPrefix(size_t k, const Ipv4Address& targetPrefix)
{
    if (k >= targetPrefix_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->targetPrefix[k] = targetPrefix;
}

void MitigationTarget::insertTargetPrefix(size_t k, const Ipv4Address& targetPrefix)
{
    handleChange();
    if (k > targetPrefix_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = targetPrefix_arraysize + 1;
    Ipv4Address *targetPrefix2 = new Ipv4Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        targetPrefix2[i] = this->targetPrefix[i];
    targetPrefix2[k] = targetPrefix;
    for (i = k + 1; i < newSize; i++)
        targetPrefix2[i] = this->targetPrefix[i-1];
    delete [] this->targetPrefix;
    this->targetPrefix = targetPrefix2;
    targetPrefix_arraysize = newSize;
}

void MitigationTarget::insertTargetPrefix(const Ipv4Address& targetPrefix)
{
    insertTargetPrefix(targetPrefix_arraysize, targetPrefix);
}

void MitigationTarget::eraseTargetPrefix(size_t k)
{
    if (k >= targetPrefix_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = targetPrefix_arraysize - 1;
    Ipv4Address *targetPrefix2 = (newSize == 0) ? nullptr : new Ipv4Address[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        targetPrefix2[i] = this->targetPrefix[i];
    for (i = k; i < newSize; i++)
        targetPrefix2[i] = this->targetPrefix[i+1];
    delete [] this->targetPrefix;
    this->targetPrefix = targetPrefix2;
    targetPrefix_arraysize = newSize;
}

size_t MitigationTarget::getPortRangeArraySize() const
{
    return portRange_arraysize;
}

const PortRange& MitigationTarget::getPortRange(size_t k) const
{
    if (k >= portRange_arraysize) throw omnetpp::cRuntimeError("Array of size portRange_arraysize indexed by %lu", (unsigned long)k);
    return this->portRange[k];
}

void MitigationTarget::setPortRangeArraySize(size_t newSize)
{
    handleChange();
    PortRange *portRange2 = (newSize==0) ? nullptr : new PortRange[newSize];
    size_t minSize = portRange_arraysize < newSize ? portRange_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        portRange2[i] = this->portRange[i];
    delete [] this->portRange;
    this->portRange = portRange2;
    portRange_arraysize = newSize;
}

void MitigationTarget::setPortRange(size_t k, const PortRange& portRange)
{
    if (k >= portRange_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->portRange[k] = portRange;
}

void MitigationTarget::insertPortRange(size_t k, const PortRange& portRange)
{
    handleChange();
    if (k > portRange_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = portRange_arraysize + 1;
    PortRange *portRange2 = new PortRange[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        portRange2[i] = this->portRange[i];
    portRange2[k] = portRange;
    for (i = k + 1; i < newSize; i++)
        portRange2[i] = this->portRange[i-1];
    delete [] this->portRange;
    this->portRange = portRange2;
    portRange_arraysize = newSize;
}

void MitigationTarget::insertPortRange(const PortRange& portRange)
{
    insertPortRange(portRange_arraysize, portRange);
}

void MitigationTarget::erasePortRange(size_t k)
{
    if (k >= portRange_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = portRange_arraysize - 1;
    PortRange *portRange2 = (newSize == 0) ? nullptr : new PortRange[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        portRange2[i] = this->portRange[i];
    for (i = k; i < newSize; i++)
        portRange2[i] = this->portRange[i+1];
    delete [] this->portRange;
    this->portRange = portRange2;
    portRange_arraysize = newSize;
}

size_t MitigationTarget::getTargetProtocolArraySize() const
{
    return targetProtocol_arraysize;
}

uint8_t MitigationTarget::getTargetProtocol(size_t k) const
{
    if (k >= targetProtocol_arraysize) throw omnetpp::cRuntimeError("Array of size targetProtocol_arraysize indexed by %lu", (unsigned long)k);
    return this->targetProtocol[k];
}

void MitigationTarget::setTargetProtocolArraySize(size_t newSize)
{
    handleChange();
    uint8_t *targetProtocol2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = targetProtocol_arraysize < newSize ? targetProtocol_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        targetProtocol2[i] = this->targetProtocol[i];
    for (size_t i = minSize; i < newSize; i++)
        targetProtocol2[i] = 0;
    delete [] this->targetProtocol;
    this->targetProtocol = targetProtocol2;
    targetProtocol_arraysize = newSize;
}

void MitigationTarget::setTargetProtocol(size_t k, uint8_t targetProtocol)
{
    if (k >= targetProtocol_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->targetProtocol[k] = targetProtocol;
}

void MitigationTarget::insertTargetProtocol(size_t k, uint8_t targetProtocol)
{
    handleChange();
    if (k > targetProtocol_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = targetProtocol_arraysize + 1;
    uint8_t *targetProtocol2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        targetProtocol2[i] = this->targetProtocol[i];
    targetProtocol2[k] = targetProtocol;
    for (i = k + 1; i < newSize; i++)
        targetProtocol2[i] = this->targetProtocol[i-1];
    delete [] this->targetProtocol;
    this->targetProtocol = targetProtocol2;
    targetProtocol_arraysize = newSize;
}

void MitigationTarget::insertTargetProtocol(uint8_t targetProtocol)
{
    insertTargetProtocol(targetProtocol_arraysize, targetProtocol);
}

void MitigationTarget::eraseTargetProtocol(size_t k)
{
    if (k >= targetProtocol_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = targetProtocol_arraysize - 1;
    uint8_t *targetProtocol2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        targetProtocol2[i] = this->targetProtocol[i];
    for (i = k; i < newSize; i++)
        targetProtocol2[i] = this->targetProtocol[i+1];
    delete [] this->targetProtocol;
    this->targetProtocol = targetProtocol2;
    targetProtocol_arraysize = newSize;
}

size_t MitigationTarget::getTargetFqdnArraySize() const
{
    return targetFqdn_arraysize;
}

const char * MitigationTarget::getTargetFqdn(size_t k) const
{
    if (k >= targetFqdn_arraysize) throw omnetpp::cRuntimeError("Array of size targetFqdn_arraysize indexed by %lu", (unsigned long)k);
    return this->targetFqdn[k].c_str();
}

void MitigationTarget::setTargetFqdnArraySize(size_t newSize)
{
    handleChange();
    omnetpp::opp_string *targetFqdn2 = (newSize==0) ? nullptr : new omnetpp::opp_string[newSize];
    size_t minSize = targetFqdn_arraysize < newSize ? targetFqdn_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        targetFqdn2[i] = this->targetFqdn[i];
    delete [] this->targetFqdn;
    this->targetFqdn = targetFqdn2;
    targetFqdn_arraysize = newSize;
}

void MitigationTarget::setTargetFqdn(size_t k, const char * targetFqdn)
{
    if (k >= targetFqdn_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->targetFqdn[k] = targetFqdn;
}

void MitigationTarget::insertTargetFqdn(size_t k, const char * targetFqdn)
{
    handleChange();
    if (k > targetFqdn_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = targetFqdn_arraysize + 1;
    omnetpp::opp_string *targetFqdn2 = new omnetpp::opp_string[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        targetFqdn2[i] = this->targetFqdn[i];
    targetFqdn2[k] = targetFqdn;
    for (i = k + 1; i < newSize; i++)
        targetFqdn2[i] = this->targetFqdn[i-1];
    delete [] this->targetFqdn;
    this->targetFqdn = targetFqdn2;
    targetFqdn_arraysize = newSize;
}

void MitigationTarget::insertTargetFqdn(const char * targetFqdn)
{
    insertTargetFqdn(targetFqdn_arraysize, targetFqdn);
}

void MitigationTarget::eraseTargetFqdn(size_t k)
{
    if (k >= targetFqdn_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = targetFqdn_arraysize - 1;
    omnetpp::opp_string *targetFqdn2 = (newSize == 0) ? nullptr : new omnetpp::opp_string[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        targetFqdn2[i] = this->targetFqdn[i];
    for (i = k; i < newSize; i++)
        targetFqdn2[i] = this->targetFqdn[i+1];
    delete [] this->targetFqdn;
    this->targetFqdn = targetFqdn2;
    targetFqdn_arraysize = newSize;
}

size_t MitigationTarget::getTargetUriArraySize() const
{
    return targetUri_arraysize;
}

const char * MitigationTarget::getTargetUri(size_t k) const
{
    if (k >= targetUri_arraysize) throw omnetpp::cRuntimeError("Array of size targetUri_arraysize indexed by %lu", (unsigned long)k);
    return this->targetUri[k].c_str();
}

void MitigationTarget::setTargetUriArraySize(size_t newSize)
{
    handleChange();
    omnetpp::opp_string *targetUri2 = (newSize==0) ? nullptr : new omnetpp::opp_string[newSize];
    size_t minSize = targetUri_arraysize < newSize ? targetUri_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        targetUri2[i] = this->targetUri[i];
    delete [] this->targetUri;
    this->targetUri = targetUri2;
    targetUri_arraysize = newSize;
}

void MitigationTarget::setTargetUri(size_t k, const char * targetUri)
{
    if (k >= targetUri_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->targetUri[k] = targetUri;
}

void MitigationTarget::insertTargetUri(size_t k, const char * targetUri)
{
    handleChange();
    if (k > targetUri_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = targetUri_arraysize + 1;
    omnetpp::opp_string *targetUri2 = new omnetpp::opp_string[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        targetUri2[i] = this->targetUri[i];
    targetUri2[k] = targetUri;
    for (i = k + 1; i < newSize; i++)
        targetUri2[i] = this->targetUri[i-1];
    delete [] this->targetUri;
    this->targetUri = targetUri2;
    targetUri_arraysize = newSize;
}

void MitigationTarget::insertTargetUri(const char * targetUri)
{
    insertTargetUri(targetUri_arraysize, targetUri);
}

void MitigationTarget::eraseTargetUri(size_t k)
{
    if (k >= targetUri_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = targetUri_arraysize - 1;
    omnetpp::opp_string *targetUri2 = (newSize == 0) ? nullptr : new omnetpp::opp_string[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        targetUri2[i] = this->targetUri[i];
    for (i = k; i < newSize; i++)
        targetUri2[i] = this->targetUri[i+1];
    delete [] this->targetUri;
    this->targetUri = targetUri2;
    targetUri_arraysize = newSize;
}

const char * MitigationTarget::getAliasName() const
{
    return this->aliasName.c_str();
}

void MitigationTarget::setAliasName(const char * aliasName)
{
    handleChange();
    this->aliasName = aliasName;
}

class MitigationTargetDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_targetPrefix,
        FIELD_portRange,
        FIELD_targetProtocol,
        FIELD_targetFqdn,
        FIELD_targetUri,
        FIELD_aliasName,
    };
  public:
    MitigationTargetDescriptor();
    virtual ~MitigationTargetDescriptor();

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

Register_ClassDescriptor(MitigationTargetDescriptor)

MitigationTargetDescriptor::MitigationTargetDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::MitigationTarget)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

MitigationTargetDescriptor::~MitigationTargetDescriptor()
{
    delete[] propertynames;
}

bool MitigationTargetDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MitigationTarget *>(obj)!=nullptr;
}

const char **MitigationTargetDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MitigationTargetDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MitigationTargetDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int MitigationTargetDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY,    // FIELD_targetPrefix
        FD_ISARRAY | FD_ISCOMPOUND,    // FIELD_portRange
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_targetProtocol
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_targetFqdn
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_targetUri
        FD_ISEDITABLE,    // FIELD_aliasName
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *MitigationTargetDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "targetPrefix",
        "portRange",
        "targetProtocol",
        "targetFqdn",
        "targetUri",
        "aliasName",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int MitigationTargetDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "targetPrefix") == 0) return base+0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "portRange") == 0) return base+1;
    if (fieldName[0] == 't' && strcmp(fieldName, "targetProtocol") == 0) return base+2;
    if (fieldName[0] == 't' && strcmp(fieldName, "targetFqdn") == 0) return base+3;
    if (fieldName[0] == 't' && strcmp(fieldName, "targetUri") == 0) return base+4;
    if (fieldName[0] == 'a' && strcmp(fieldName, "aliasName") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MitigationTargetDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Ipv4Address",    // FIELD_targetPrefix
        "inet::PortRange",    // FIELD_portRange
        "uint8_t",    // FIELD_targetProtocol
        "string",    // FIELD_targetFqdn
        "string",    // FIELD_targetUri
        "string",    // FIELD_aliasName
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **MitigationTargetDescriptor::getFieldPropertyNames(int field) const
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

const char *MitigationTargetDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int MitigationTargetDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MitigationTarget *pp = (MitigationTarget *)object; (void)pp;
    switch (field) {
        case FIELD_targetPrefix: return pp->getTargetPrefixArraySize();
        case FIELD_portRange: return pp->getPortRangeArraySize();
        case FIELD_targetProtocol: return pp->getTargetProtocolArraySize();
        case FIELD_targetFqdn: return pp->getTargetFqdnArraySize();
        case FIELD_targetUri: return pp->getTargetUriArraySize();
        default: return 0;
    }
}

const char *MitigationTargetDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MitigationTarget *pp = (MitigationTarget *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MitigationTargetDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MitigationTarget *pp = (MitigationTarget *)object; (void)pp;
    switch (field) {
        case FIELD_targetPrefix: return pp->getTargetPrefix(i).str();
        case FIELD_portRange: {std::stringstream out; out << pp->getPortRange(i); return out.str();}
        case FIELD_targetProtocol: return ulong2string(pp->getTargetProtocol(i));
        case FIELD_targetFqdn: return oppstring2string(pp->getTargetFqdn(i));
        case FIELD_targetUri: return oppstring2string(pp->getTargetUri(i));
        case FIELD_aliasName: return oppstring2string(pp->getAliasName());
        default: return "";
    }
}

bool MitigationTargetDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MitigationTarget *pp = (MitigationTarget *)object; (void)pp;
    switch (field) {
        case FIELD_targetProtocol: pp->setTargetProtocol(i,string2ulong(value)); return true;
        case FIELD_targetFqdn: pp->setTargetFqdn(i,(value)); return true;
        case FIELD_targetUri: pp->setTargetUri(i,(value)); return true;
        case FIELD_aliasName: pp->setAliasName((value)); return true;
        default: return false;
    }
}

const char *MitigationTargetDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_portRange: return omnetpp::opp_typename(typeid(PortRange));
        default: return nullptr;
    };
}

void *MitigationTargetDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MitigationTarget *pp = (MitigationTarget *)object; (void)pp;
    switch (field) {
        case FIELD_targetPrefix: return toVoidPtr(&pp->getTargetPrefix(i)); break;
        case FIELD_portRange: return toVoidPtr(&pp->getPortRange(i)); break;
        default: return nullptr;
    }
}

Register_Class(MitigationCreate)

MitigationCreate::MitigationCreate() : ::inet::MitigationTarget()
{
}

MitigationCreate::MitigationCreate(const MitigationCreate& other) : ::inet::MitigationTarget(other)
{
    copy(other);
}

MitigationCreate::~MitigationCreate()
{
}

MitigationCreate& MitigationCreate::operator=(const MitigationCreate& other)
{
    if (this == &other) return *this;
    ::inet::MitigationTarget::operator=(other);
    copy(other);
    return *this;
}

void MitigationCreate::copy(const MitigationCreate& other)
{
    this->lifetime = other.lifetime;
    this->triggerMitigation = other.triggerMitigation;
}

void MitigationCreate::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::MitigationTarget::parsimPack(b);
    doParsimPacking(b,this->lifetime);
    doParsimPacking(b,this->triggerMitigation);
}

void MitigationCreate::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::MitigationTarget::parsimUnpack(b);
    doParsimUnpacking(b,this->lifetime);
    doParsimUnpacking(b,this->triggerMitigation);
}

int32_t MitigationCreate::getLifetime() const
{
    return this->lifetime;
}

void MitigationCreate::setLifetime(int32_t lifetime)
{
    handleChange();
    this->lifetime = lifetime;
}

bool MitigationCreate::getTriggerMitigation() const
{
    return this->triggerMitigation;
}

void MitigationCreate::setTriggerMitigation(bool triggerMitigation)
{
    handleChange();
    this->triggerMitigation = triggerMitigation;
}

class MitigationCreateDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_lifetime,
        FIELD_triggerMitigation,
    };
  public:
    MitigationCreateDescriptor();
    virtual ~MitigationCreateDescriptor();

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

Register_ClassDescriptor(MitigationCreateDescriptor)

MitigationCreateDescriptor::MitigationCreateDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::MitigationCreate)), "inet::MitigationTarget")
{
    propertynames = nullptr;
}

MitigationCreateDescriptor::~MitigationCreateDescriptor()
{
    delete[] propertynames;
}

bool MitigationCreateDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MitigationCreate *>(obj)!=nullptr;
}

const char **MitigationCreateDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MitigationCreateDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MitigationCreateDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int MitigationCreateDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_lifetime
        FD_ISEDITABLE,    // FIELD_triggerMitigation
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *MitigationCreateDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lifetime",
        "triggerMitigation",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int MitigationCreateDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lifetime") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "triggerMitigation") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MitigationCreateDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int32_t",    // FIELD_lifetime
        "bool",    // FIELD_triggerMitigation
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **MitigationCreateDescriptor::getFieldPropertyNames(int field) const
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

const char *MitigationCreateDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int MitigationCreateDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MitigationCreate *pp = (MitigationCreate *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MitigationCreateDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MitigationCreate *pp = (MitigationCreate *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MitigationCreateDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MitigationCreate *pp = (MitigationCreate *)object; (void)pp;
    switch (field) {
        case FIELD_lifetime: return long2string(pp->getLifetime());
        case FIELD_triggerMitigation: return bool2string(pp->getTriggerMitigation());
        default: return "";
    }
}

bool MitigationCreateDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MitigationCreate *pp = (MitigationCreate *)object; (void)pp;
    switch (field) {
        case FIELD_lifetime: pp->setLifetime(string2long(value)); return true;
        case FIELD_triggerMitigation: pp->setTriggerMitigation(string2bool(value)); return true;
        default: return false;
    }
}

const char *MitigationCreateDescriptor::getFieldStructName(int field) const
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

void *MitigationCreateDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MitigationCreate *pp = (MitigationCreate *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(MitigationStatistics)

MitigationStatistics::MitigationStatistics() : ::inet::MitigationCreate()
{
}

MitigationStatistics::MitigationStatistics(const MitigationStatistics& other) : ::inet::MitigationCreate(other)
{
    copy(other);
}

MitigationStatistics::~MitigationStatistics()
{
}

MitigationStatistics& MitigationStatistics::operator=(const MitigationStatistics& other)
{
    if (this == &other) return *this;
    ::inet::MitigationCreate::operator=(other);
    copy(other);
    return *this;
}

void MitigationStatistics::copy(const MitigationStatistics& other)
{
    this->mitigationStart = other.mitigationStart;
    this->status = other.status;
    this->bytesDropped = other.bytesDropped;
    this->bpsDropped = other.bpsDropped;
    this->pktsDropped = other.pktsDropped;
    this->ppsDropped = other.ppsDropped;
}

void MitigationStatistics::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::MitigationCreate::parsimPack(b);
    doParsimPacking(b,this->mitigationStart);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->bytesDropped);
    doParsimPacking(b,this->bpsDropped);
    doParsimPacking(b,this->pktsDropped);
    doParsimPacking(b,this->ppsDropped);
}

void MitigationStatistics::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::MitigationCreate::parsimUnpack(b);
    doParsimUnpacking(b,this->mitigationStart);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->bytesDropped);
    doParsimUnpacking(b,this->bpsDropped);
    doParsimUnpacking(b,this->pktsDropped);
    doParsimUnpacking(b,this->ppsDropped);
}

uint64_t MitigationStatistics::getMitigationStart() const
{
    return this->mitigationStart;
}

void MitigationStatistics::setMitigationStart(uint64_t mitigationStart)
{
    handleChange();
    this->mitigationStart = mitigationStart;
}

inet::MitigationStatus MitigationStatistics::getStatus() const
{
    return this->status;
}

void MitigationStatistics::setStatus(inet::MitigationStatus status)
{
    handleChange();
    this->status = status;
}

long MitigationStatistics::getBytesDropped() const
{
    return this->bytesDropped;
}

void MitigationStatistics::setBytesDropped(long bytesDropped)
{
    handleChange();
    this->bytesDropped = bytesDropped;
}

long MitigationStatistics::getBpsDropped() const
{
    return this->bpsDropped;
}

void MitigationStatistics::setBpsDropped(long bpsDropped)
{
    handleChange();
    this->bpsDropped = bpsDropped;
}

long MitigationStatistics::getPktsDropped() const
{
    return this->pktsDropped;
}

void MitigationStatistics::setPktsDropped(long pktsDropped)
{
    handleChange();
    this->pktsDropped = pktsDropped;
}

long MitigationStatistics::getPpsDropped() const
{
    return this->ppsDropped;
}

void MitigationStatistics::setPpsDropped(long ppsDropped)
{
    handleChange();
    this->ppsDropped = ppsDropped;
}

class MitigationStatisticsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_mitigationStart,
        FIELD_status,
        FIELD_bytesDropped,
        FIELD_bpsDropped,
        FIELD_pktsDropped,
        FIELD_ppsDropped,
    };
  public:
    MitigationStatisticsDescriptor();
    virtual ~MitigationStatisticsDescriptor();

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

Register_ClassDescriptor(MitigationStatisticsDescriptor)

MitigationStatisticsDescriptor::MitigationStatisticsDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::MitigationStatistics)), "inet::MitigationCreate")
{
    propertynames = nullptr;
}

MitigationStatisticsDescriptor::~MitigationStatisticsDescriptor()
{
    delete[] propertynames;
}

bool MitigationStatisticsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MitigationStatistics *>(obj)!=nullptr;
}

const char **MitigationStatisticsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MitigationStatisticsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MitigationStatisticsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int MitigationStatisticsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_mitigationStart
        0,    // FIELD_status
        FD_ISEDITABLE,    // FIELD_bytesDropped
        FD_ISEDITABLE,    // FIELD_bpsDropped
        FD_ISEDITABLE,    // FIELD_pktsDropped
        FD_ISEDITABLE,    // FIELD_ppsDropped
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *MitigationStatisticsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "mitigationStart",
        "status",
        "bytesDropped",
        "bpsDropped",
        "pktsDropped",
        "ppsDropped",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int MitigationStatisticsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "mitigationStart") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "status") == 0) return base+1;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bytesDropped") == 0) return base+2;
    if (fieldName[0] == 'b' && strcmp(fieldName, "bpsDropped") == 0) return base+3;
    if (fieldName[0] == 'p' && strcmp(fieldName, "pktsDropped") == 0) return base+4;
    if (fieldName[0] == 'p' && strcmp(fieldName, "ppsDropped") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MitigationStatisticsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint64_t",    // FIELD_mitigationStart
        "inet::MitigationStatus",    // FIELD_status
        "long",    // FIELD_bytesDropped
        "long",    // FIELD_bpsDropped
        "long",    // FIELD_pktsDropped
        "long",    // FIELD_ppsDropped
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **MitigationStatisticsDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_status: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MitigationStatisticsDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyname, "enum")) return "inet::MitigationStatus";
            return nullptr;
        default: return nullptr;
    }
}

int MitigationStatisticsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MitigationStatistics *pp = (MitigationStatistics *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MitigationStatisticsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MitigationStatistics *pp = (MitigationStatistics *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MitigationStatisticsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MitigationStatistics *pp = (MitigationStatistics *)object; (void)pp;
    switch (field) {
        case FIELD_mitigationStart: return uint642string(pp->getMitigationStart());
        case FIELD_status: return enum2string(pp->getStatus(), "inet::MitigationStatus");
        case FIELD_bytesDropped: return long2string(pp->getBytesDropped());
        case FIELD_bpsDropped: return long2string(pp->getBpsDropped());
        case FIELD_pktsDropped: return long2string(pp->getPktsDropped());
        case FIELD_ppsDropped: return long2string(pp->getPpsDropped());
        default: return "";
    }
}

bool MitigationStatisticsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MitigationStatistics *pp = (MitigationStatistics *)object; (void)pp;
    switch (field) {
        case FIELD_mitigationStart: pp->setMitigationStart(string2uint64(value)); return true;
        case FIELD_bytesDropped: pp->setBytesDropped(string2long(value)); return true;
        case FIELD_bpsDropped: pp->setBpsDropped(string2long(value)); return true;
        case FIELD_pktsDropped: pp->setPktsDropped(string2long(value)); return true;
        case FIELD_ppsDropped: pp->setPpsDropped(string2long(value)); return true;
        default: return false;
    }
}

const char *MitigationStatisticsDescriptor::getFieldStructName(int field) const
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

void *MitigationStatisticsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MitigationStatistics *pp = (MitigationStatistics *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(MitigationEfficacy)

MitigationEfficacy::MitigationEfficacy() : ::inet::FieldsChunk()
{
}

MitigationEfficacy::MitigationEfficacy(const MitigationEfficacy& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

MitigationEfficacy::~MitigationEfficacy()
{
}

MitigationEfficacy& MitigationEfficacy::operator=(const MitigationEfficacy& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void MitigationEfficacy::copy(const MitigationEfficacy& other)
{
    this->attackStatus = other.attackStatus;
}

void MitigationEfficacy::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->attackStatus);
}

void MitigationEfficacy::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->attackStatus);
}

bool MitigationEfficacy::getAttackStatus() const
{
    return this->attackStatus;
}

void MitigationEfficacy::setAttackStatus(bool attackStatus)
{
    handleChange();
    this->attackStatus = attackStatus;
}

class MitigationEfficacyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_attackStatus,
    };
  public:
    MitigationEfficacyDescriptor();
    virtual ~MitigationEfficacyDescriptor();

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

Register_ClassDescriptor(MitigationEfficacyDescriptor)

MitigationEfficacyDescriptor::MitigationEfficacyDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::MitigationEfficacy)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

MitigationEfficacyDescriptor::~MitigationEfficacyDescriptor()
{
    delete[] propertynames;
}

bool MitigationEfficacyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MitigationEfficacy *>(obj)!=nullptr;
}

const char **MitigationEfficacyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MitigationEfficacyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MitigationEfficacyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int MitigationEfficacyDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_attackStatus
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *MitigationEfficacyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "attackStatus",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int MitigationEfficacyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "attackStatus") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MitigationEfficacyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_attackStatus
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **MitigationEfficacyDescriptor::getFieldPropertyNames(int field) const
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

const char *MitigationEfficacyDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int MitigationEfficacyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MitigationEfficacy *pp = (MitigationEfficacy *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MitigationEfficacyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MitigationEfficacy *pp = (MitigationEfficacy *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MitigationEfficacyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MitigationEfficacy *pp = (MitigationEfficacy *)object; (void)pp;
    switch (field) {
        case FIELD_attackStatus: return bool2string(pp->getAttackStatus());
        default: return "";
    }
}

bool MitigationEfficacyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MitigationEfficacy *pp = (MitigationEfficacy *)object; (void)pp;
    switch (field) {
        case FIELD_attackStatus: pp->setAttackStatus(string2bool(value)); return true;
        default: return false;
    }
}

const char *MitigationEfficacyDescriptor::getFieldStructName(int field) const
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

void *MitigationEfficacyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MitigationEfficacy *pp = (MitigationEfficacy *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

