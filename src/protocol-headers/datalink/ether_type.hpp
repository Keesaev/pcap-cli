#pragma once

#include <stdint.h>

enum class ether_type : uint16_t {
    ipv4 = 0x0800, // Internet Protocol version 4 (IPv4)
    arp = 0x0806, // Address Resolution Protocol (ARP)
    wol = 0x0842, // Wake-on-LAN[8]
    avtp = 0x22F0, // Audio Video Transport Protocol (AVTP)
    trill = 0x22F3, // IETF TRILL Protocol
    srp = 0x22EA, // Stream Reservation Protocol
    dec_mop_rc = 0x6002, // DEC MOP RC
    de_cnet = 0x6003, // DECnet Phase IV, DNA Routing
    dec_lat = 0x6004, // DEC LAT
    rarp = 0x8035, // Reverse Address Resolution Protocol (RARP)
    ether_talk = 0x809B, // AppleTalk (Ethertalk)
    aarp = 0x80F3, // AppleTalk Address Resolution Protocol (AARP)
    dot1q = 0x8100, // VLAN-tagged frame (IEEE 802.1Q) and Shortest Path Bridging IEEE 802.1aq with NNI compatibility[9]
    slpp = 0x8102, // Simple Loop Prevention Protocol (SLPP)
    vlacp = 0x8103, // Virtual Link Aggregation Control Protocol (VLACP)
    ipx = 0x8137, // IPX
    qnx = 0x8204, // QNX Qnet
    ipv6 = 0x86DD, // Internet Protocol Version 6 (IPv6)
    eth_flow_ctrl = 0x8808, // Ethernet flow control
    lacp = 0x8809, // Ethernet Slow Protocols[10] such as the Link Aggregation Control Protocol (LACP)
    cobra_net = 0x8819, // CobraNet
    mpls_uni = 0x8847, // MPLS unicast
    mpls_multi = 0x8848, // MPLS multicast
    pppoe_disc = 0x8863, // PPPoE Discovery Stage
    pppoe_ses = 0x8864, // PPPoE Session Stage
    home_plug = 0x887B, // HomePlug 1.0 MME
    eap = 0x888E, // EAP over LAN (IEEE 802.1X)
    profinet = 0x8892, // PROFINET Protocol
    scsi_eth = 0x889A, // HyperSCSI (SCSI over Ethernet)
    ata_eth = 0x88A2, // ATA over Ethernet
    ether_cat = 0x88A4, // EtherCAT Protocol
    q_in_q = 0x88A8, // Service VLAN tag identifier (S-Tag) on Q-in-Q tunnel.
    eth_pl = 0x88AB, // Ethernet Powerlink
    goose = 0x88B8, // GOOSE (Generic Object Oriented Substation event)
    gse = 0x88B9, // GSE (Generic Substation Events) Management Services
    sv = 0x88BA, // SV (Sampled Value Transmission)
    romon = 0x88BF, // MikroTik RoMON (unofficial)
    lldp = 0x88CC, // Link Layer Discovery Protocol (LLDP)
    sercos_3 = 0x88CD, // SERCOS III
    homeplug = 0x88E1, // HomePlug Green PHY
    mrp = 0x88E3, // Media Redundancy Protocol (IEC62439-2)
    macsec = 0x88E5, // IEEE 802.1AE MAC security (MACsec)
    pbb = 0x88E7, // Provider Backbone Bridges (PBB) (IEEE 802.1ah)
    ptp = 0x88F7, // Precision Time Protocol (PTP) over IEEE 802.3 Ethernet
    ns_si = 0x88F8, // NC-SI
    prp = 0x88FB, // Parallel Redundancy Protocol (PRP)
    cfm = 0x8902, // IEEE 802.1ag Connectivity Fault Management (CFM) Protocol / ITU-T Recommendation Y.1731 (OAM)
    fcoe_f = 0x8906, // Fibre Channel over Ethernet (FCoE)
    fcoe_i = 0x8914, // FCoE Initialization Protocol
    roce = 0x8915, // RDMA over Converged Ethernet (RoCE)
    tte = 0x891D, // TTEthernet Protocol Control Frame (TTE)
    ieee_1905 = 0x893a, // 1905.1 IEEE Protocol
    hsr = 0x892F, // High-availability Seamless Redundancy (HSR)
    eth_test = 0x9000, // Ethernet Configuration Testing Protocol[11]
    tsn = 0xF1C1, // Redundancy Tag (IEEE 802.1CB Frame Replication and Elimination for Reliability)
};