//
// Generated file, do not edit! Created by nedtool 5.6 from inet/_extra/applications/codefagent/CoDefHeartbeat.msg.
//

#ifndef __INET_CODEFHEARTBEAT_M_H
#define __INET_CODEFHEARTBEAT_M_H

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

class Heartbeat;
} // namespace inet


namespace inet {

/**
 * Class generated from <tt>inet/_extra/applications/codefagent/CoDefHeartbeat.msg:18</tt> by nedtool.
 * <pre>
 * class Heartbeat
 * {
 *     bool peerHbStatus;
 * }
 * </pre>
 */
class INET_API Heartbeat
{
  protected:
    bool peerHbStatus = false;

  private:
    void copy(const Heartbeat& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Heartbeat&);

  public:
    Heartbeat();
    Heartbeat(const Heartbeat& other);
    virtual ~Heartbeat();
    Heartbeat& operator=(const Heartbeat& other);
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual bool getPeerHbStatus() const;
    virtual void setPeerHbStatus(bool peerHbStatus);
};

} // namespace inet

#endif // ifndef __INET_CODEFHEARTBEAT_M_H
