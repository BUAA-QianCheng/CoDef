//
// Generated file, do not edit! Created by nedtool 5.6 from inet/_extra/applications/codefagent/CoDefFilterRules.msg.
//

#ifndef __INET_CODEFFILTERRULES_M_H
#define __INET_CODEFFILTERRULES_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API
#  endif
#endif


namespace inet {

class Statistics;
class Ace;
class Acl;
class Acls;
} // namespace inet

#include "inet/_extra/networklayer/FilterRule_m.h" // import inet._extra.networklayer.FilterRule


namespace inet {

/**
 * Class generated from <tt>inet/_extra/applications/codefagent/CoDefFilterRules.msg:20</tt> by nedtool.
 * <pre>
 * class Statistics
 * {
 *     long matchedPackets;
 *     long matchedOctets;
 * }
 * </pre>
 */
class INET_API Statistics
{
  protected:
    long matchedPackets = 0;
    long matchedOctets = 0;

  private:
    void copy(const Statistics& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Statistics&);

  public:
    Statistics();
    Statistics(const Statistics& other);
    virtual ~Statistics();
    Statistics& operator=(const Statistics& other);
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual long getMatchedPackets() const;
    virtual void setMatchedPackets(long matchedPackets);
    virtual long getMatchedOctets() const;
    virtual void setMatchedOctets(long matchedOctets);
};

/**
 * Class generated from <tt>inet/_extra/applications/codefagent/CoDefFilterRules.msg:25</tt> by nedtool.
 * <pre>
 * class Ace
 * {
 *     string name;
 *     Matches matches;
 *     Action action;
 *     Statistics statistics;
 * }
 * </pre>
 */
class INET_API Ace
{
  protected:
    omnetpp::opp_string name;
    Matches matches;
    Action action;
    Statistics statistics;

  private:
    void copy(const Ace& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Ace&);

  public:
    Ace();
    Ace(const Ace& other);
    virtual ~Ace();
    Ace& operator=(const Ace& other);
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual const char * getName() const;
    virtual void setName(const char * name);
    virtual const Matches& getMatches() const;
    virtual Matches& getMatchesForUpdate() { return const_cast<Matches&>(const_cast<Ace*>(this)->getMatches());}
    virtual void setMatches(const Matches& matches);
    virtual const Action& getAction() const;
    virtual Action& getActionForUpdate() { return const_cast<Action&>(const_cast<Ace*>(this)->getAction());}
    virtual void setAction(const Action& action);
    virtual const Statistics& getStatistics() const;
    virtual Statistics& getStatisticsForUpdate() { return const_cast<Statistics&>(const_cast<Ace*>(this)->getStatistics());}
    virtual void setStatistics(const Statistics& statistics);
};

/**
 * Enum generated from <tt>inet/_extra/applications/codefagent/CoDefFilterRules.msg:32</tt> by nedtool.
 * <pre>
 * enum ActivationType
 * {
 *     ACTIVITE_WHEN_MITIGATING = 1; //The ACLs is installed only when a mitigation is active for the client.
 *     IMMEDIATE = 2; //The ACL is immediately activated.
 *     DEACTIVATE = 3; //The ACL is maintained by the DOTS server, but it isdeactivated.
 * }
 * </pre>
 */
enum ActivationType {
    ACTIVITE_WHEN_MITIGATING = 1,
    IMMEDIATE = 2,
    DEACTIVATE = 3
};

/**
 * Class generated from <tt>inet/_extra/applications/codefagent/CoDefFilterRules.msg:39</tt> by nedtool.
 * <pre>
 * class Acl
 * {
 *     string name;
 *     string type;
 *     ActivationType activitionType;
 *     int PendingLifetime;
 *     Ace ace[];
 * }
 * </pre>
 */
class INET_API Acl
{
  protected:
    omnetpp::opp_string name;
    omnetpp::opp_string type;
    inet::ActivationType activitionType = static_cast<inet::ActivationType>(-1);
    int PendingLifetime = 0;
    Ace *ace = nullptr;
    size_t ace_arraysize = 0;

  private:
    void copy(const Acl& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Acl&);

  public:
    Acl();
    Acl(const Acl& other);
    virtual ~Acl();
    Acl& operator=(const Acl& other);
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual const char * getName() const;
    virtual void setName(const char * name);
    virtual const char * getType() const;
    virtual void setType(const char * type);
    virtual inet::ActivationType getActivitionType() const;
    virtual void setActivitionType(inet::ActivationType activitionType);
    virtual int getPendingLifetime() const;
    virtual void setPendingLifetime(int PendingLifetime);
    virtual void setAceArraySize(size_t size);
    virtual size_t getAceArraySize() const;
    virtual const Ace& getAce(size_t k) const;
    virtual Ace& getAceForUpdate(size_t k) { return const_cast<Ace&>(const_cast<Acl*>(this)->getAce(k));}
    virtual void setAce(size_t k, const Ace& ace);
    virtual void insertAce(const Ace& ace);
    virtual void insertAce(size_t k, const Ace& ace);
    virtual void eraseAce(size_t k);
};

/**
 * Class generated from <tt>inet/_extra/applications/codefagent/CoDefFilterRules.msg:47</tt> by nedtool.
 * <pre>
 * class Acls
 * {
 *     Acl acls[];
 * }
 * </pre>
 */
class INET_API Acls
{
  protected:
    Acl *acls = nullptr;
    size_t acls_arraysize = 0;

  private:
    void copy(const Acls& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Acls&);

  public:
    Acls();
    Acls(const Acls& other);
    virtual ~Acls();
    Acls& operator=(const Acls& other);
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual void setAclsArraySize(size_t size);
    virtual size_t getAclsArraySize() const;
    virtual const Acl& getAcls(size_t k) const;
    virtual Acl& getAclsForUpdate(size_t k) { return const_cast<Acl&>(const_cast<Acls*>(this)->getAcls(k));}
    virtual void setAcls(size_t k, const Acl& acls);
    virtual void insertAcls(const Acl& acls);
    virtual void insertAcls(size_t k, const Acl& acls);
    virtual void eraseAcls(size_t k);
};

} // namespace inet

#endif // ifndef __INET_CODEFFILTERRULES_M_H

