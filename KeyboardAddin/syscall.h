/*
File: syscall.h 
Author: Simon Lothar, Myth
Usage: Define the syscall functions.

Thanks Simon Lothar for his great contribution in syscall.
*/


#ifndef _SYSCALL_H_
#define _SYSCALL_H_

#ifdef __cplusplus
extern "C" 
{
#endif


// syscall related
#define SCA 0xD201D002
#define SCB 0x422B0009
#define SCE 0x80010070


typedef int (*sc_Comm_Open)(unsigned short);
extern const unsigned int sc28D[4];
// int Comm_Open(unsigned short parameters)
// If parameters ANDed with 0xF0 is 0x20, the USB communication channel will be opened,
// else syscall 0x02AB (Serial_Open) is called with parameters.
// 0 if successful
// 3 if already open
#define Comm_Open (*(sc_Comm_Open)sc28D)


typedef int (*sc_Comm_Close)(int);
extern const unsigned int sc28E[4];
// int Comm_Close(int mode)
// Resets all buffers; disables the corresponding hardware
// if mode=1 then Comm_Close does an immediate close, t. i. it does not wait for pending transmissions.
// if mode!=1 then Comm_Close quits returning code 5 if transmissions are under way.
// returns
// 0 if successful
// 5 if aware of pending transmissions and transmissions are under way
#define Comm_Close (*(sc_Comm_Close)sc28E)


typedef int (*sc_Comm_WaitForAnyBuffer)(int, int, int*);
extern const unsigned int sc28F[4];
// int Comm_WaitForAnyBuffer(int timeout_ms, int P2, int*P3)
// timeout has to be at least 25 ms.
// P2 : if 1 the wait for receive buffer else wait for transmit buffer
// P3 : if assigned, the elapsed time is returned in *P3. 
// returns 5 : comm not open
// returns 6 : timeout
// returns 8 : physically disconnected
// returns 0x0A : manual break
#define Comm_WaitForAnyBuffer (*(sc_Comm_WaitForAnyBuffer)sc28F)


typedef int (*sc_Comm_ReadOneByte)(unsigned char*);
extern const unsigned int sc290[4];
// int Comm_ReadOneByte(unsigned char* result)
// Fetches one byte from the actual opened communication pipe into result.
// The function waits for 1000 ms max.
// returns
// 0 if successful
// 5 if the channel is not open.
// 6 a timeout occurred
#define Comm_ReadOneByte (*(sc_Comm_ReadOneByte)sc290)


typedef int (*sc_Comm_TransmitOneByte)(unsigned char);
extern const unsigned int sc291[4];
// int Comm_TransmitOneByte(unsigned char byte_to_transmit)
// Puts one byte into the transmit buffer.
// returns
// 0 if successful, 
// 2 if no space is available in the serial interrupt transmit buffer (256 bytes max)
// 3 if the serial channel is not open.
#define Comm_TransmitOneByte (*(sc_Comm_TransmitOneByte)sc291)


typedef int (*sc_Comm_WaitForAndReadNBytes)(char*, int);
extern const unsigned int sc292[4];
// int Comm_ReadOneByte(char* buffer, int bytes_to_read)
// Waits for bytes_to_read bytes and reads them as the case may be.
// The function waits for 3000 ms max.
// returns
// 0 if successful
// 5 if the channel is not open.
// 6 a timeout occurred
// 0x0A terminated
#define Comm_WaitForAndReadNBytes (*(sc_Comm_WaitForAndReadNBytes)sc292)


typedef int (*sc_Comm_TransmitNBytes)(unsigned char*, int);
extern const unsigned int sc293[4];
// int Comm_TransmitNBytes(unsigned char* bytes_to_transmit, int requested_count)
// Puts requested_count bytes from the array bytes_to_transmit into the transmit buffer, if space allows.
// returns
// 0 if successful, 
// 2 if no space is available in the serial interrupt transmit buffer (256 bytes max)
// 3 if the serial channel is not open.
#define Comm_TransmitNBytes (*(sc_Comm_TransmitNBytes)sc293)


typedef int (*sc_Comm_ClearReceiveBuffer)(void);
extern const unsigned int sc294[4];
// int Comm_ClearReceiveBuffer(void)
// Clears the receive buffer.
// returns
// 0 if successful, 
// 3 if the serial channel is not open.
#define Comm_ClearReceiveBuffer (*(sc_Comm_ClearReceiveBuffer)sc294)


typedef int (*sc_Comm_ClearTransmitBuffer)(void);
extern const unsigned int sc295[4];
// int Comm_ClearTransmitBuffer(void)
// Clears the transmit buffer.
// returns 0 in any case
#define Comm_ClearTransmitBuffer (*(sc_Comm_ClearTransmitBuffer)sc295)


typedef int (*sc_Comm_IsOpen)(void);
extern const unsigned int sc298[4];
// int Comm_IsOpen(void)
// returns 3 if not open
// returns 1 if open
#define Comm_IsOpen (*(sc_Comm_IsOpen)sc298)


typedef int (*sc_itoa)(int, unsigned int*);
extern const unsigned int sc541[4];
// int itoa(int number, unsigned int* buffer)
// itoa fails to convert 0x80000000.
#define itoa (*(sc_itoa)sc541)


#ifdef __cplusplus
}
#endif

#endif