// Copyright (c) 2012 The Native Client Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/* From private/ppb_tcp_server_socket_private.idl,
 *   modified Tue Feb 14 12:24:48 2012.
 */

#ifndef PPAPI_C_PRIVATE_PPB_TCP_SERVER_SOCKET_PRIVATE_H_
#define PPAPI_C_PRIVATE_PPB_TCP_SERVER_SOCKET_PRIVATE_H_

#include "ppapi/c/private/ppb_net_address_private.h"
#include "ppapi/c/pp_bool.h"
#include "ppapi/c/pp_completion_callback.h"
#include "ppapi/c/pp_instance.h"
#include "ppapi/c/pp_macros.h"
#include "ppapi/c/pp_resource.h"
#include "ppapi/c/pp_stdint.h"

#define PPB_TCPSERVERSOCKET_PRIVATE_INTERFACE_0_1 \
    "PPB_TCPServerSocket_Private;0.1"
#define PPB_TCPSERVERSOCKET_PRIVATE_INTERFACE \
    PPB_TCPSERVERSOCKET_PRIVATE_INTERFACE_0_1

/**
 * @file
 * This file defines the <code>PPB_TCPServerSocket_Private</code> interface.
 */


/**
 * @addtogroup Interfaces
 * @{
 */
/**
 * The <code>PPB_TCPServerSocket_Private</code> interface provides TCP
 * server socket operations.
 */
struct PPB_TCPServerSocket_Private_0_1 {
  /**
   * Allocates a TCP server socket resource.
   */
  PP_Resource (*Create)(PP_Instance instance);
  /**
   * Determines if a given resource is TCP server socket.
   */
  PP_Bool (*IsTCPServerSocket)(PP_Resource resource);
  /**
   * Binds |tcp_server_socket| to the address given by |addr| and
   * starts listening.  The |backlog| argument defines the maximum
   * length to which the queue of pending connections may
   * grow. |callback| is invoked when |tcp_server_socket| is ready to
   * accept incoming connections or in the case of failure. Returns
   * PP_ERROR_NOSPACE if socket can't be initialized, or
   * PP_ERROR_FAILED in the case of Listen failure. Otherwise, returns
   * PP_OK.
   */
  int32_t (*Listen)(PP_Resource tcp_server_socket,
                    const struct PP_NetAddress_Private* addr,
                    int32_t backlog,
                    struct PP_CompletionCallback callback);
  /**
   * Accepts single connection, creates instance of
   * PPB_TCPSocket_Private and stores reference to it in
   * |tcp_socket|. |callback| is invoked when connection is accepted
   * or in the case of failure. This method can be called only after
   * succesfull Listen call on |tcp_server_socket|.
   */
  int32_t (*Accept)(PP_Resource tcp_server_socket,
                    PP_Resource* tcp_socket,
                    struct PP_CompletionCallback callback);
  /**
   * Cancels all pending callbacks reporting PP_ERROR_ABORTED and
   * closes the socket. Note: this method is implicitly called when
   * server socket is destroyed.
   */
  void (*StopListening)(PP_Resource tcp_server_socket);
};

typedef struct PPB_TCPServerSocket_Private_0_1 PPB_TCPServerSocket_Private;
/**
 * @}
 */

#endif  /* PPAPI_C_PRIVATE_PPB_TCP_SERVER_SOCKET_PRIVATE_H_ */

