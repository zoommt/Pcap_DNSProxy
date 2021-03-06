﻿// This code is part of Pcap_DNSProxy
// A local DNS server based on WinPcap and LibPcap
// Copyright (C) 2012-2016 Chengr28
// 
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.


#include "Base.h"

#if defined(ENABLE_LIBSODIUM)
//Global variables
extern CONFIGURATION_TABLE Parameter;
extern GLOBAL_STATUS GlobalRunningStatus;
extern ALTERNATE_SWAP_TABLE AlternateSwapList;
extern DNSCURVE_CONFIGURATION_TABLE DNSCurveParameter;

//Functions
SSIZE_T __fastcall DNSCurvePaddingData(
	const bool SetPadding, 
	char *Buffer, 
	const SSIZE_T Length);
size_t __fastcall DNSCurveSelectTargetSocket(
	SOCKET_DATA *TargetSocketData, 
	DNSCURVE_SERVER_DATA **PacketTarget, 
	bool **IsAlternate, 
	size_t **AlternateTimeoutTimes, 
	const uint16_t Protocol);
bool __fastcall DNSCurveSelectTargetSocketMulti(
	bool &IsIPv6, 
	bool **IsAlternate, 
	const uint16_t Protocol);
bool __fastcall DNSCurvePacketTargetSetting(
	const size_t ServerType, 
	DNSCURVE_SERVER_DATA **PacketTarget);
bool __fastcall DNSCurvePrecomputationKeySetting(
	uint8_t *PrecomputationKey, 
	uint8_t *Client_PublicKey, 
	const unsigned char *ServerFingerprint);
void __fastcall DNSCurveSocketPrecomputation(
	const uint16_t Protocol, 
	const char *OriginalSend, 
	const size_t SendSize, 
	const size_t RecvSize, 
	uint8_t **PrecomputationKey, 
	uint8_t **Alternate_PrecomputationKey, 
	DNSCURVE_SERVER_DATA **PacketTarget, 
	std::vector<SOCKET_DATA> &SocketDataList, 
	std::vector<DNSCURVE_SOCKET_SELECTING_DATA> &SocketSelectingList, 
	std::shared_ptr<char> &SendBuffer, 
	size_t &DataLength, 
	std::shared_ptr<char> &Alternate_SendBuffer, 
	size_t &Alternate_DataLength);
size_t __fastcall DNSCurvePacketEncryption(
	const uint16_t Protocol, 
	const char *SendMagicNumber, 
	const unsigned char *Client_PublicKey, 
	const unsigned char *PrecomputationKey, 
	const char *OriginalSend, 
	const size_t Length, 
	char *SendBuffer, 
	const size_t SendSize);
SSIZE_T DNSCurvePacketDecryption(
	const char *ReceiveMagicNumber, 
	const unsigned char *PrecomputationKey, 
	char *OriginalRecv, 
	const size_t RecvSize, 
	const SSIZE_T Length);
SSIZE_T __fastcall DNSCurveSocketSelecting(
	const uint16_t Protocol, 
	std::vector<SOCKET_DATA> &SocketDataList, 
	std::vector<DNSCURVE_SOCKET_SELECTING_DATA> &SocketSelectingList, 
	char *OriginalRecv, 
	const size_t RecvSize, 
	SSIZE_T *ErrorCode);
SSIZE_T __fastcall DNSCurveSelectingResult(
	const uint16_t Protocol, 
	std::vector<SOCKET_DATA> &SocketDataList, 
	std::vector<DNSCURVE_SOCKET_SELECTING_DATA> &SocketSelectingList, 
	char *OriginalRecv, 
	const size_t RecvSize);
bool __fastcall DNSCurveTCPSignatureRequest(
	const uint16_t Protocol, 
	const bool IsAlternate);
bool __fastcall DNSCurveUDPSignatureRequest(
	const uint16_t Protocol, 
	const bool IsAlternate);
bool __fastcall DNSCruveGetSignatureData(
	const char *Buffer, 
	const size_t ServerType);
#endif
