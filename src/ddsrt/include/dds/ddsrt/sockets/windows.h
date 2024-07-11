#ifndef DDSRT_WINDOWS_SOCKET_H
#define DDSRT_WINDOWS_SOCKET_H

#include <winsock2.h>
#include <mswsock.h> // Required for MSG_TRUNC when compiling with mingw-w64.
#include <ws2tcpip.h>
#include "dds/ddsrt/iovec.h"

#if defined(__cplusplus)
extern "C" {
#endif

#ifdef _WIN32
 typedef int sock_t;
#else
 typedef SOCKET sock_t;
#endif
typedef sock_t ddsrt_socket_t;

#define DDSRT_INVALID_SOCKET (INVALID_SOCKET)
#define PRIdSOCK PRIuPTR

typedef struct ddsrt_socket_ext_t {
  ddsrt_socket_t sock;
  LPFN_WSARECVMSG wsarecvmsg;
} ddsrt_socket_ext_t;

#define IFF_POINTOPOINT IFF_POINTTOPOINT

// Required when compiling with mingw-w64.
#ifndef MCAST_JOIN_SOURCE_GROUP
#define MCAST_JOIN_SOURCE_GROUP 45
#endif
#ifndef MCAST_LEAVE_SOURCE_GROUP
#define MCAST_LEAVE_SOURCE_GROUP 46
#endif

typedef struct ddsrt_msghdr {
  void *msg_name;
  socklen_t msg_namelen;
  ddsrt_iovec_t *msg_iov;
  ddsrt_msg_iovlen_t msg_iovlen;
  void *msg_control;
  size_t msg_controllen;
  int msg_flags;
} ddsrt_msghdr_t;

#define DDSRT_MSGHDR_FLAGS 1

#if defined(__cplusplus)
}
#endif

#endif /* DDSRT_WINDOWS_SOCKET_H */
