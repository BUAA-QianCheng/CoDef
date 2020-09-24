//
// Generated file, do not edit! Created by nedtool 5.6 from inet/_extra/applications/codefagent/CoDefFilterRules.msg.
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
#include "CoDefFilterRules_m.h"

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

Statistics::Statistics()
{
}

Statistics::Statistics(const Statistics& other)
{
    copy(other);
}

Statistics::~Statistics()
{
}

Statistics& Statistics::operator=(const Statistics& other)
{
    if (this == &other) return *this;
    copy(other);
    return *this;
}

void Statistics::copy(const Statistics& other)
{
    this->matchedPackets = other.matchedPackets;
    this->matchedOctets = other.matchedOctets;
}

void Statistics::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->matchedPackets);
    doParsimPacking(b,this->matchedOctets);
}

void Statistics::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->matchedPackets);
    doParsimUnpacking(b,this->matchedOctets);
}

long Statistics::getMatchedPackets() const
{
    return this->matchedPackets;
}

void Statistics::setMatchedPackets(long matchedPackets)
{
    this->matchedPackets = matchedPackets;
}

long Statistics::getMatchedOctets() const
{
    return this->matchedOctets;
}

void Statistics::setMatchedOctets(long matchedOctets)
{
    this->matchedOctets = matchedOctets;
}

class StatisticsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_matchedPackets,
        FIELD_matchedOctets,
    };
  public:
    StatisticsDescriptor();
    virtual ~StatisticsDescriptor();

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

Register_ClassDescriptor(StatisticsDescriptor)

StatisticsDescriptor::StatisticsDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Statistics)), "")
{
    propertynames = nullptr;
}

StatisticsDescriptor::~StatisticsDescriptor()
{
    delete[] propertynames;
}

bool StatisticsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Statistics *>(obj)!=nullptr;
}

const char **StatisticsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *StatisticsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int StatisticsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int StatisticsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_matchedPackets
        FD_ISEDITABLE,    // FIELD_matchedOctets
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *StatisticsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "matchedPackets",
        "matchedOctets",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int StatisticsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "matchedPackets") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "matchedOctets") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *StatisticsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "long",    // FIELD_matchedPackets
        "long",    // FIELD_matchedOctets
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **StatisticsDescriptor::getFieldPropertyNames(int field) const
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

const char *StatisticsDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int StatisticsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Statistics *pp = (Statistics *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *StatisticsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Statistics *pp = (Statistics *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string StatisticsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Statistics *pp = (Statistics *)object; (void)pp;
    switch (field) {
        case FIELD_matchedPackets: return long2string(pp->getMatchedPackets());
        case FIELD_matchedOctets: return long2string(pp->getMatchedOctets());
        default: return "";
    }
}

bool StatisticsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Statistics *pp = (Statistics *)object; (void)pp;
    switch (field) {
        case FIELD_matchedPackets: pp->setMatchedPackets(string2long(value)); return true;
        case FIELD_matchedOctets: pp->setMatchedOctets(string2long(value)); return true;
        default: return false;
    }
}

const char *StatisticsDescriptor::getFieldStructName(int field) const
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

void *StatisticsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Statistics *pp = (Statistics *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Ace::Ace()
{
}

Ace::Ace(const Ace& other)
{
    copy(other);
}

Ace::~Ace()
{
}

Ace& Ace::operator=(const Ace& other)
{
    if (this == &other) return *this;
    copy(other);
    return *this;
}

void Ace::copy(const Ace& other)
{
    this->name = other.name;
    this->matches = other.matches;
    this->action = other.action;
    this->statistics = other.statistics;
}

void Ace::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->name);
    doParsimPacking(b,this->matches);
    doParsimPacking(b,this->action);
    doParsimPacking(b,this->statistics);
}

void Ace::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->name);
    doParsimUnpacking(b,this->matches);
    doParsimUnpacking(b,this->action);
    doParsimUnpacking(b,this->statistics);
}

const char * Ace::getName() const
{
    return this->name.c_str();
}

void Ace::setName(const char * name)
{
    this->name = name;
}

const Matches& Ace::getMatches() const
{
    return this->matches;
}

void Ace::setMatches(const Matches& matches)
{
    this->matches = matches;
}

const Action& Ace::getAction() const
{
    return this->action;
}

void Ace::setAction(const Action& action)
{
    this->action = action;
}

const Statistics& Ace::getStatistics() const
{
    return this->statistics;
}

void Ace::setStatistics(const Statistics& statistics)
{
    this->statistics = statistics;
}

class AceDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_name,
        FIELD_matches,
        FIELD_action,
        FIELD_statistics,
    };
  public:
    AceDescriptor();
    virtual ~AceDescriptor();

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

Register_ClassDescriptor(AceDescriptor)

AceDescriptor::AceDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Ace)), "")
{
    propertynames = nullptr;
}

AceDescriptor::~AceDescriptor()
{
    delete[] propertynames;
}

bool AceDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ace *>(obj)!=nullptr;
}

const char **AceDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AceDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AceDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int AceDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_name
        FD_ISCOMPOUND,    // FIELD_matches
        FD_ISCOMPOUND,    // FIELD_action
        FD_ISCOMPOUND,    // FIELD_statistics
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *AceDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "name",
        "matches",
        "action",
        "statistics",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int AceDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "name") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "matches") == 0) return base+1;
    if (fieldName[0] == 'a' && strcmp(fieldName, "action") == 0) return base+2;
    if (fieldName[0] == 's' && strcmp(fieldName, "statistics") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AceDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_name
        "inet::Matches",    // FIELD_matches
        "inet::Action",    // FIELD_action
        "inet::Statistics",    // FIELD_statistics
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **AceDescriptor::getFieldPropertyNames(int field) const
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

const char *AceDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int AceDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ace *pp = (Ace *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *AceDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ace *pp = (Ace *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AceDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ace *pp = (Ace *)object; (void)pp;
    switch (field) {
        case FIELD_name: return oppstring2string(pp->getName());
        case FIELD_matches: {std::stringstream out; out << pp->getMatches(); return out.str();}
        case FIELD_action: {std::stringstream out; out << pp->getAction(); return out.str();}
        case FIELD_statistics: {std::stringstream out; out << pp->getStatistics(); return out.str();}
        default: return "";
    }
}

bool AceDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ace *pp = (Ace *)object; (void)pp;
    switch (field) {
        case FIELD_name: pp->setName((value)); return true;
        default: return false;
    }
}

const char *AceDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_matches: return omnetpp::opp_typename(typeid(Matches));
        case FIELD_action: return omnetpp::opp_typename(typeid(Action));
        case FIELD_statistics: return omnetpp::opp_typename(typeid(Statistics));
        default: return nullptr;
    };
}

void *AceDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ace *pp = (Ace *)object; (void)pp;
    switch (field) {
        case FIELD_matches: return toVoidPtr(&pp->getMatches()); break;
        case FIELD_action: return toVoidPtr(&pp->getAction()); break;
        case FIELD_statistics: return toVoidPtr(&pp->getStatistics()); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ActivationType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ActivationType"));
    e->insert(ACTIVITE_WHEN_MITIGATING, "ACTIVITE_WHEN_MITIGATING");
    e->insert(IMMEDIATE, "IMMEDIATE");
    e->insert(DEACTIVATE, "DEACTIVATE");
)

Acl::Acl()
{
}

Acl::Acl(const Acl& other)
{
    copy(other);
}

Acl::~Acl()
{
    delete [] this->ace;
}

Acl& Acl::operator=(const Acl& other)
{
    if (this == &other) return *this;
    copy(other);
    return *this;
}

void Acl::copy(const Acl& other)
{
    this->name = other.name;
    this->type = other.type;
    this->activitionType = other.activitionType;
    this->PendingLifetime = other.PendingLifetime;
    delete [] this->ace;
    this->ace = (other.ace_arraysize==0) ? nullptr : new Ace[other.ace_arraysize];
    ace_arraysize = other.ace_arraysize;
    for (size_t i = 0; i < ace_arraysize; i++) {
        this->ace[i] = other.ace[i];
    }
}

void Acl::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->name);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->activitionType);
    doParsimPacking(b,this->PendingLifetime);
    b->pack(ace_arraysize);
    doParsimArrayPacking(b,this->ace,ace_arraysize);
}

void Acl::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->name);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->activitionType);
    doParsimUnpacking(b,this->PendingLifetime);
    delete [] this->ace;
    b->unpack(ace_arraysize);
    if (ace_arraysize == 0) {
        this->ace = nullptr;
    } else {
        this->ace = new Ace[ace_arraysize];
        doParsimArrayUnpacking(b,this->ace,ace_arraysize);
    }
}

const char * Acl::getName() const
{
    return this->name.c_str();
}

void Acl::setName(const char * name)
{
    this->name = name;
}

const char * Acl::getType() const
{
    return this->type.c_str();
}

void Acl::setType(const char * type)
{
    this->type = type;
}

inet::ActivationType Acl::getActivitionType() const
{
    return this->activitionType;
}

void Acl::setActivitionType(inet::ActivationType activitionType)
{
    this->activitionType = activitionType;
}

int Acl::getPendingLifetime() const
{
    return this->PendingLifetime;
}

void Acl::setPendingLifetime(int PendingLifetime)
{
    this->PendingLifetime = PendingLifetime;
}

size_t Acl::getAceArraySize() const
{
    return ace_arraysize;
}

const Ace& Acl::getAce(size_t k) const
{
    if (k >= ace_arraysize) throw omnetpp::cRuntimeError("Array of size ace_arraysize indexed by %lu", (unsigned long)k);
    return this->ace[k];
}

void Acl::setAceArraySize(size_t newSize)
{
    Ace *ace2 = (newSize==0) ? nullptr : new Ace[newSize];
    size_t minSize = ace_arraysize < newSize ? ace_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        ace2[i] = this->ace[i];
    delete [] this->ace;
    this->ace = ace2;
    ace_arraysize = newSize;
}

void Acl::setAce(size_t k, const Ace& ace)
{
    if (k >= ace_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->ace[k] = ace;
}

void Acl::insertAce(size_t k, const Ace& ace)
{
    if (k > ace_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = ace_arraysize + 1;
    Ace *ace2 = new Ace[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        ace2[i] = this->ace[i];
    ace2[k] = ace;
    for (i = k + 1; i < newSize; i++)
        ace2[i] = this->ace[i-1];
    delete [] this->ace;
    this->ace = ace2;
    ace_arraysize = newSize;
}

void Acl::insertAce(const Ace& ace)
{
    insertAce(ace_arraysize, ace);
}

void Acl::eraseAce(size_t k)
{
    if (k >= ace_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = ace_arraysize - 1;
    Ace *ace2 = (newSize == 0) ? nullptr : new Ace[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        ace2[i] = this->ace[i];
    for (i = k; i < newSize; i++)
        ace2[i] = this->ace[i+1];
    delete [] this->ace;
    this->ace = ace2;
    ace_arraysize = newSize;
}

class AclDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_name,
        FIELD_type,
        FIELD_activitionType,
        FIELD_PendingLifetime,
        FIELD_ace,
    };
  public:
    AclDescriptor();
    virtual ~AclDescriptor();

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

Register_ClassDescriptor(AclDescriptor)

AclDescriptor::AclDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Acl)), "")
{
    propertynames = nullptr;
}

AclDescriptor::~AclDescriptor()
{
    delete[] propertynames;
}

bool AclDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Acl *>(obj)!=nullptr;
}

const char **AclDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AclDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AclDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int AclDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_name
        FD_ISEDITABLE,    // FIELD_type
        0,    // FIELD_activitionType
        FD_ISEDITABLE,    // FIELD_PendingLifetime
        FD_ISARRAY | FD_ISCOMPOUND,    // FIELD_ace
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *AclDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "name",
        "type",
        "activitionType",
        "PendingLifetime",
        "ace",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int AclDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "name") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "type") == 0) return base+1;
    if (fieldName[0] == 'a' && strcmp(fieldName, "activitionType") == 0) return base+2;
    if (fieldName[0] == 'P' && strcmp(fieldName, "PendingLifetime") == 0) return base+3;
    if (fieldName[0] == 'a' && strcmp(fieldName, "ace") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AclDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_name
        "string",    // FIELD_type
        "inet::ActivationType",    // FIELD_activitionType
        "int",    // FIELD_PendingLifetime
        "inet::Ace",    // FIELD_ace
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **AclDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_activitionType: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *AclDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_activitionType:
            if (!strcmp(propertyname, "enum")) return "inet::ActivationType";
            return nullptr;
        default: return nullptr;
    }
}

int AclDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Acl *pp = (Acl *)object; (void)pp;
    switch (field) {
        case FIELD_ace: return pp->getAceArraySize();
        default: return 0;
    }
}

const char *AclDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Acl *pp = (Acl *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AclDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Acl *pp = (Acl *)object; (void)pp;
    switch (field) {
        case FIELD_name: return oppstring2string(pp->getName());
        case FIELD_type: return oppstring2string(pp->getType());
        case FIELD_activitionType: return enum2string(pp->getActivitionType(), "inet::ActivationType");
        case FIELD_PendingLifetime: return long2string(pp->getPendingLifetime());
        case FIELD_ace: {std::stringstream out; out << pp->getAce(i); return out.str();}
        default: return "";
    }
}

bool AclDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Acl *pp = (Acl *)object; (void)pp;
    switch (field) {
        case FIELD_name: pp->setName((value)); return true;
        case FIELD_type: pp->setType((value)); return true;
        case FIELD_PendingLifetime: pp->setPendingLifetime(string2long(value)); return true;
        default: return false;
    }
}

const char *AclDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_ace: return omnetpp::opp_typename(typeid(Ace));
        default: return nullptr;
    };
}

void *AclDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Acl *pp = (Acl *)object; (void)pp;
    switch (field) {
        case FIELD_ace: return toVoidPtr(&pp->getAce(i)); break;
        default: return nullptr;
    }
}

Acls::Acls()
{
}

Acls::Acls(const Acls& other)
{
    copy(other);
}

Acls::~Acls()
{
    delete [] this->acls;
}

Acls& Acls::operator=(const Acls& other)
{
    if (this == &other) return *this;
    copy(other);
    return *this;
}

void Acls::copy(const Acls& other)
{
    delete [] this->acls;
    this->acls = (other.acls_arraysize==0) ? nullptr : new Acl[other.acls_arraysize];
    acls_arraysize = other.acls_arraysize;
    for (size_t i = 0; i < acls_arraysize; i++) {
        this->acls[i] = other.acls[i];
    }
}

void Acls::parsimPack(omnetpp::cCommBuffer *b) const
{
    b->pack(acls_arraysize);
    doParsimArrayPacking(b,this->acls,acls_arraysize);
}

void Acls::parsimUnpack(omnetpp::cCommBuffer *b)
{
    delete [] this->acls;
    b->unpack(acls_arraysize);
    if (acls_arraysize == 0) {
        this->acls = nullptr;
    } else {
        this->acls = new Acl[acls_arraysize];
        doParsimArrayUnpacking(b,this->acls,acls_arraysize);
    }
}

size_t Acls::getAclsArraySize() const
{
    return acls_arraysize;
}

const Acl& Acls::getAcls(size_t k) const
{
    if (k >= acls_arraysize) throw omnetpp::cRuntimeError("Array of size acls_arraysize indexed by %lu", (unsigned long)k);
    return this->acls[k];
}

void Acls::setAclsArraySize(size_t newSize)
{
    Acl *acls2 = (newSize==0) ? nullptr : new Acl[newSize];
    size_t minSize = acls_arraysize < newSize ? acls_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        acls2[i] = this->acls[i];
    delete [] this->acls;
    this->acls = acls2;
    acls_arraysize = newSize;
}

void Acls::setAcls(size_t k, const Acl& acls)
{
    if (k >= acls_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    this->acls[k] = acls;
}

void Acls::insertAcls(size_t k, const Acl& acls)
{
    if (k > acls_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = acls_arraysize + 1;
    Acl *acls2 = new Acl[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        acls2[i] = this->acls[i];
    acls2[k] = acls;
    for (i = k + 1; i < newSize; i++)
        acls2[i] = this->acls[i-1];
    delete [] this->acls;
    this->acls = acls2;
    acls_arraysize = newSize;
}

void Acls::insertAcls(const Acl& acls)
{
    insertAcls(acls_arraysize, acls);
}

void Acls::eraseAcls(size_t k)
{
    if (k >= acls_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    size_t newSize = acls_arraysize - 1;
    Acl *acls2 = (newSize == 0) ? nullptr : new Acl[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        acls2[i] = this->acls[i];
    for (i = k; i < newSize; i++)
        acls2[i] = this->acls[i+1];
    delete [] this->acls;
    this->acls = acls2;
    acls_arraysize = newSize;
}

class AclsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_acls,
    };
  public:
    AclsDescriptor();
    virtual ~AclsDescriptor();

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

Register_ClassDescriptor(AclsDescriptor)

AclsDescriptor::AclsDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::Acls)), "")
{
    propertynames = nullptr;
}

AclsDescriptor::~AclsDescriptor()
{
    delete[] propertynames;
}

bool AclsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Acls *>(obj)!=nullptr;
}

const char **AclsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AclsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AclsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int AclsDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND,    // FIELD_acls
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *AclsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "acls",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int AclsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "acls") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AclsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Acl",    // FIELD_acls
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **AclsDescriptor::getFieldPropertyNames(int field) const
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

const char *AclsDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int AclsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Acls *pp = (Acls *)object; (void)pp;
    switch (field) {
        case FIELD_acls: return pp->getAclsArraySize();
        default: return 0;
    }
}

const char *AclsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Acls *pp = (Acls *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AclsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Acls *pp = (Acls *)object; (void)pp;
    switch (field) {
        case FIELD_acls: {std::stringstream out; out << pp->getAcls(i); return out.str();}
        default: return "";
    }
}

bool AclsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Acls *pp = (Acls *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *AclsDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_acls: return omnetpp::opp_typename(typeid(Acl));
        default: return nullptr;
    };
}

void *AclsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Acls *pp = (Acls *)object; (void)pp;
    switch (field) {
        case FIELD_acls: return toVoidPtr(&pp->getAcls(i)); break;
        default: return nullptr;
    }
}

} // namespace inet

