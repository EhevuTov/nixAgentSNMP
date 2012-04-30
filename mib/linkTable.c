/*
 * Note: this file originally auto-generated by mib2c using
 *       version $ of $ 
 *
 * $Id:$
 */
/** \page MFD helper for linkTable
 *
 * \section intro Introduction
 * Introductory text.
 *
 */
/*
 * standard Net-SNMP includes 
 */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/*
 * include our parent header 
 */
#include "linkTable.h"

#include <net-snmp/agent/mib_modules.h>

#include "linkTable_interface.h"

const oid       linkTable_oid[] = { LINKTABLE_OID };

const int       linkTable_oid_size = OID_LENGTH(linkTable_oid);

linkTable_registration linkTable_user_context;

void            initialize_table_linkTable(void);
void            shutdown_table_linkTable(void);


/**
 * Initializes the linkTable module
 */
void
init_linkTable(void)
{
    DEBUGMSGTL(("verbose:linkTable:init_linkTable", "called\n"));

    /*
     * TODO:300:o: Perform linkTable one-time module initialization.
     */

    /*
     * here we initialize all the tables we're planning on supporting
     */
    if (should_init("linkTable"))
        initialize_table_linkTable();

}                               /* init_linkTable */

/**
 * Shut-down the linkTable module (agent is exiting)
 */
void
shutdown_linkTable(void)
{
    if (should_init("linkTable"))
        shutdown_table_linkTable();

}

/**
 * Initialize the table linkTable 
 *    (Define its contents and how it's structured)
 */
void
initialize_table_linkTable(void)
{
    linkTable_registration *user_context;
    u_long          flags;

    DEBUGMSGTL(("verbose:linkTable:initialize_table_linkTable",
                "called\n"));

    /*
     * TODO:301:o: Perform linkTable one-time table initialization.
     */

    /*
     * TODO:302:o: |->Initialize linkTable user context
     * if you'd like to pass in a pointer to some data for this
     * table, allocate or set it up here.
     */
    /*
     * a netsnmp_data_list is a simple way to store void pointers. A simple
     * string token is used to add, find or remove pointers.
     */
    user_context = netsnmp_create_data_list("linkTable", NULL, NULL);

    /*
     * No support for any flags yet, but in the future you would
     * set any flags here.
     */
    flags = 0;

    /*
     * call interface initialization code
     */
    _linkTable_initialize_interface(user_context, flags);
}                               /* initialize_table_linkTable */

/**
 * Shutdown the table linkTable 
 */
void
shutdown_table_linkTable(void)
{
    /*
     * call interface shutdown code
     */
    _linkTable_shutdown_interface(&linkTable_user_context);
}

/**
 * pre-request callback
 *
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_ERROR                : other error
 */
int
linkTable_pre_request(linkTable_registration * user_context)
{
    DEBUGMSGTL(("verbose:linkTable:linkTable_pre_request", "called\n"));

    /*
     * TODO:510:o: Perform linkTable pre-request actions.
     */

    return MFD_SUCCESS;
}                               /* linkTable_pre_request */

/**
 * post-request callback
 *
 * Note:
 *   New rows have been inserted into the container, and
 *   deleted rows have been removed from the container and
 *   released.
 *
 * @param user_context
 * @param rc : MFD_SUCCESS if all requests succeeded
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : other error (ignored)
 */
int
linkTable_post_request(linkTable_registration * user_context, int rc)
{
    DEBUGMSGTL(("verbose:linkTable:linkTable_post_request", "called\n"));

    /*
     * TODO:511:o: Perform linkTable post-request actions.
     */

    return MFD_SUCCESS;
}                               /* linkTable_post_request */


/** @{ */
