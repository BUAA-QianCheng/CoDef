# CoDef

An Simulation Library of DDoS Cooperative Defence Based on OMNeT++ and INET Framework.

基于OMNeT++仿真环境和INET框架的DDoS协同防御仿真库。

# Introduction-简介

OMNeT++  https://omnetpp.org/

OMNeT++ is an extensible, modular, component-based C++ simulation library and framework, primarily for building network simulators. “Network” is meant in a broader sense that includes wired and wireless communication networks, on-chip networks, queueing networks, and so on. Domain-specific functionality such as support for sensor networks, wireless ad-hoc networks, Internet protocols, performance modeling, photonic networks, etc., is provided by model frameworks, developed as independent projects. OMNeT++ offers an Eclipse-based IDE, a graphical runtime environment, and a host of other tools. There are extensions for real-time simulation, network emulation, database integration, SystemC integration, and several other functions.

OMNeT ++是可扩展的，基于组件的模块化C ++仿真库和框架，主要用于构建网络仿真器。“网络”在广义上意味着包括有线和无线通信网络，片上网络，排队网络等。通过作为独立项目开发的模型框架提供了特定于域的功能，例如对传感器网络，无线自组织网络，Internet协议，性能建模，光子网络等的支持。OMNeT ++提供了一个基于Eclipse的IDE，一个图形运行时环境以及许多其他工具。实时仿真，网络仿真，数据库集成，SystemC集成和其他一些功能都有扩展。

INET Framework  https://inet.omnetpp.org/

INET Framework is an open-source model library for the OMNeT++ simulation environment. It provides protocols, agents and other models for researchers and students working with communication networks. INET is especially useful when designing and validating new protocols, or exploring new or exotic scenarios.INET contains models for the Internet stack (TCP, UDP, IPv4, IPv6, OSPF, BGP, etc.), wired and wireless link layer protocols (Ethernet, PPP, IEEE 802.11, etc), support for mobility, MANET protocols, DiffServ, MPLS with LDP and RSVP-TE signalling, several application models, and many other protocols and components.

INET Framework是OMNeT ++仿真环境的开源模型库。它为使用通信网络的研究人员和学生提供协议，代理和其他模型。在设计和验证新协议，或探索新的或特殊的情况时，INET尤其有用。INET包含以下模型：互联网堆栈（TCP，UDP，IPv4，IPv6，OSPF，BGP等），有线和无线链路层协议（以太网，PPP，IEEE 802.11等），对移动性的支持，MANET协议，DiffServ，具有LDP和RSVP-TE信令的MPLS，几种应用模型以及许多其他协议和组件。

CoDef

CoDef is a Simulation Library Based on OMNeT++ and INET Framework. It provides simulation models of DDoS Cooperative Defence and basic DDoS attacks.

CoDef 是基于OMNeT++仿真环境和INET框架的仿真库。它提供DDoS协同防御和基本的DDoS的攻击的仿真模型。

# Installing-安装

1. Download and Install OMNeT++ 5.6.2 and INET Framework 4.2.0.

2. Copy "_extra" folder into src folder of INET (for example "inet/src/inet/_extra") and copy "images" folder into  images folder of OMNeT++(images/_extra)

3. Build INET

# Run-运行

