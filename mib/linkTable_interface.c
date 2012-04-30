/*
 * Note: this file originally auto-generated by mib2c using
 *       version $ of $ 
 *
 * $Id:$
 */
/*
 * *********************************************************************
 * *********************************************************************
 * *********************************************************************
 * ***                                                               ***
 * ***  NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE  ***
 * ***                                                               ***
 * ***                                                               ***
 * ***       THIS FILE DOES NOT CONTAIN ANY USER EDITABLE CODE.      ***
 * ***                                                               ***
 * ***                                                               ***
 * ***       THE GENERATED CODE IS INTERNAL IMPLEMENTATION, AND      ***
 * ***                                                               ***
 * ***                                                               ***
 * ***    IS SUBJECT TO CHANGE WITHOUT WARNING IN FUTURE RELEASES.   ***
 * ***                                                               ***
 * ***                                                               ***
 * *********************************************************************
 * *********************************************************************
 * *********************************************************************
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


#include <net-snmp/agent/table_container.h>
#include <net-snmp/library/container.h>

#include "linkTable_interface.h"

netsnmp_feature_require(baby_steps)
    netsnmp_feature_require(row_merge)
    netsnmp_feature_require(check_all_requests_error)
#include <ctype.h>
/**********************************************************************
 **********************************************************************
 ***
 *** Table linkTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * MYCORP-PRODUCT-MYPRODUCT-MIB::linkTable is subid 1 of myCorpProductMIB.
     * Its status is Current.
     * OID: .1.3.6.1.4.1.36872.2.1.1.1, length: 11
     */
     typedef struct linkTable_interface_ctx_s {

         netsnmp_container *container;
         netsnmp_cache  *cache;

         linkTable_registration *user_ctx;

         netsnmp_table_registration_info tbl_info;

         netsnmp_baby_steps_access_methods access_multiplexer;

     } linkTable_interface_ctx;

     static linkTable_interface_ctx linkTable_if_ctx;

     static void     _linkTable_container_init(linkTable_interface_ctx *
                                               if_ctx);
     static void     _linkTable_container_shutdown(linkTable_interface_ctx
                                                   * if_ctx);


     netsnmp_container *linkTable_container_get(void)
{
    return linkTable_if_ctx.container;
}

linkTable_registration *
linkTable_registration_get(void)
{
    return linkTable_if_ctx.user_ctx;
}

linkTable_registration *
linkTable_registration_set(linkTable_registration * newreg)
{
    linkTable_registration *old = linkTable_if_ctx.user_ctx;
    linkTable_if_ctx.user_ctx = newreg;
    return old;
}

int
linkTable_container_size(void)
{
    return CONTAINER_SIZE(linkTable_if_ctx.container);
}

/*
 * mfd multiplexer modes
 */
static Netsnmp_Node_Handler _mfd_linkTable_pre_request;
static Netsnmp_Node_Handler _mfd_linkTable_post_request;
static Netsnmp_Node_Handler _mfd_linkTable_object_lookup;
static Netsnmp_Node_Handler _mfd_linkTable_get_values;
/**
 * @internal
 * Initialize the table linkTable 
 *    (Define its contents and how it's structured)
 */
void
_linkTable_initialize_interface(linkTable_registration * reg_ptr,
                                u_long flags)
{
    netsnmp_baby_steps_access_methods *access_multiplexer =
        &linkTable_if_ctx.access_multiplexer;
    netsnmp_table_registration_info *tbl_info = &linkTable_if_ctx.tbl_info;
    netsnmp_handler_registration *reginfo;
    netsnmp_mib_handler *handler;
    int             mfd_modes = 0;

    DEBUGMSGTL(("internal:linkTable:_linkTable_initialize_interface",
                "called\n"));


    /*************************************************
     *
     * save interface context for linkTable
     */
    /*
     * Setting up the table's definition
     */
    netsnmp_table_helper_add_indexes(tbl_info, ASN_UNSIGNED,
                                                /** index: linkIndex */
                                     0);

    /*
     * Define the minimum and maximum accessible columns.  This
     * optimizes retrieval. 
     */
    tbl_info->min_column = LINKTABLE_MIN_COL;
    tbl_info->max_column = LINKTABLE_MAX_COL;

    /*
     * save users context
     */
    linkTable_if_ctx.user_ctx = reg_ptr;

    /*
     * call data access initialization code
     */
    linkTable_init_data(reg_ptr);

    /*
     * set up the container
     */
    _linkTable_container_init(&linkTable_if_ctx);
    if (NULL == linkTable_if_ctx.container) {
        snmp_log(LOG_ERR,
                 "could not initialize container for linkTable\n");
        return;
    }

    /*
     * access_multiplexer: REQUIRED wrapper for get request handling
     */
    access_multiplexer->object_lookup = _mfd_linkTable_object_lookup;
    access_multiplexer->get_values = _mfd_linkTable_get_values;

    /*
     * no wrappers yet
     */
    access_multiplexer->pre_request = _mfd_linkTable_pre_request;
    access_multiplexer->post_request = _mfd_linkTable_post_request;


    /*************************************************
     *
     * Create a registration, save our reg data, register table.
     */
    DEBUGMSGTL(("linkTable:init_linkTable",
                "Registering linkTable as a mibs-for-dummies table.\n"));
    handler =
        netsnmp_baby_steps_access_multiplexer_get(access_multiplexer);
    reginfo =
        netsnmp_handler_registration_create("linkTable", handler,
                                            linkTable_oid,
                                            linkTable_oid_size,
                                            HANDLER_CAN_BABY_STEP |
                                            HANDLER_CAN_RONLY);
    if (NULL == reginfo) {
        snmp_log(LOG_ERR, "error registering table linkTable\n");
        return;
    }
    reginfo->my_reg_void = &linkTable_if_ctx;

    /*************************************************
     *
     * set up baby steps handler, create it and inject it
     */
    if (access_multiplexer->object_lookup)
        mfd_modes |= BABY_STEP_OBJECT_LOOKUP;
#ifndef NETSNMP_NO_WRITE_SUPPORT
    if (access_multiplexer->set_values)
        mfd_modes |= BABY_STEP_SET_VALUES;
    if (access_multiplexer->irreversible_commit)
        mfd_modes |= BABY_STEP_IRREVERSIBLE_COMMIT;
    if (access_multiplexer->object_syntax_checks)
        mfd_modes |= BABY_STEP_CHECK_OBJECT;
#endif                          /* NETSNMP_NO_WRITE_SUPPORT */

    if (access_multiplexer->pre_request)
        mfd_modes |= BABY_STEP_PRE_REQUEST;
    if (access_multiplexer->post_request)
        mfd_modes |= BABY_STEP_POST_REQUEST;

#ifndef NETSNMP_NO_WRITE_SUPPORT
    if (access_multiplexer->undo_setup)
        mfd_modes |= BABY_STEP_UNDO_SETUP;
    if (access_multiplexer->undo_cleanup)
        mfd_modes |= BABY_STEP_UNDO_CLEANUP;
    if (access_multiplexer->undo_sets)
        mfd_modes |= BABY_STEP_UNDO_SETS;

    if (access_multiplexer->row_creation)
        mfd_modes |= BABY_STEP_ROW_CREATE;
    if (access_multiplexer->consistency_checks)
        mfd_modes |= BABY_STEP_CHECK_CONSISTENCY;
    if (access_multiplexer->commit)
        mfd_modes |= BABY_STEP_COMMIT;
    if (access_multiplexer->undo_commit)
        mfd_modes |= BABY_STEP_UNDO_COMMIT;
#endif                          /* NETSNMP_NO_WRITE_SUPPORT */

    handler = netsnmp_baby_steps_handler_get(mfd_modes);
    netsnmp_inject_handler(reginfo, handler);

    /*************************************************
     *
     * inject row_merge helper with prefix rootoid_len + 2 (entry.col)
     */
    handler = netsnmp_get_row_merge_handler(reginfo->rootoid_len + 2);
    netsnmp_inject_handler(reginfo, handler);

    /*************************************************
     *
     * inject container_table helper
     */
    handler =
        netsnmp_container_table_handler_get(tbl_info,
                                            linkTable_if_ctx.container,
                                            TABLE_CONTAINER_KEY_NETSNMP_INDEX);
    netsnmp_inject_handler(reginfo, handler);

    /*************************************************
     *
     * inject cache helper
     */
    if (NULL != linkTable_if_ctx.cache) {
        handler = netsnmp_cache_handler_get(linkTable_if_ctx.cache);
        netsnmp_inject_handler(reginfo, handler);
    }

    /*
     * register table
     */
    netsnmp_register_table(reginfo, tbl_info);

}                               /* _linkTable_initialize_interface */

/**
 * @internal
 * Shutdown the table linkTable
 */
void
_linkTable_shutdown_interface(linkTable_registration * reg_ptr)
{
    /*
     * shutdown the container
     */
    _linkTable_container_shutdown(&linkTable_if_ctx);
}

void
linkTable_valid_columns_set(netsnmp_column_info *vc)
{
    linkTable_if_ctx.tbl_info.valid_columns = vc;
}                               /* linkTable_valid_columns_set */

/**
 * @internal
 * convert the index component stored in the context to an oid
 */
int
linkTable_index_to_oid(netsnmp_index * oid_idx,
                       linkTable_mib_index * mib_idx)
{
    int             err = SNMP_ERR_NOERROR;

    /*
     * temp storage for parsing indexes
     */
    /*
     * linkIndex(1)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/a/w/e/r/d/h
     */
    netsnmp_variable_list var_linkIndex;

    /*
     * set up varbinds
     */
    memset(&var_linkIndex, 0x00, sizeof(var_linkIndex));
    var_linkIndex.type = ASN_UNSIGNED;

    /*
     * chain temp index varbinds together
     */
    var_linkIndex.next_variable = NULL;


    DEBUGMSGTL(("verbose:linkTable:linkTable_index_to_oid", "called\n"));

    /*
     * linkIndex(1)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/a/w/e/r/d/h 
     */
    snmp_set_var_value(&var_linkIndex, &mib_idx->linkIndex,
                       sizeof(mib_idx->linkIndex));


    err = build_oid_noalloc(oid_idx->oids, oid_idx->len, &oid_idx->len,
                            NULL, 0, &var_linkIndex);
    if (err)
        snmp_log(LOG_ERR, "error %d converting index to oid\n", err);

    /*
     * parsing may have allocated memory. free it.
     */
    snmp_reset_var_buffers(&var_linkIndex);

    return err;
}                               /* linkTable_index_to_oid */

/**
 * extract linkTable indexes from a netsnmp_index
 *
 * @retval SNMP_ERR_NOERROR  : no error
 * @retval SNMP_ERR_GENERR   : error
 */
int
linkTable_index_from_oid(netsnmp_index * oid_idx,
                         linkTable_mib_index * mib_idx)
{
    int             err = SNMP_ERR_NOERROR;

    /*
     * temp storage for parsing indexes
     */
    /*
     * linkIndex(1)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/a/w/e/r/d/h
     */
    netsnmp_variable_list var_linkIndex;

    /*
     * set up varbinds
     */
    memset(&var_linkIndex, 0x00, sizeof(var_linkIndex));
    var_linkIndex.type = ASN_UNSIGNED;

    /*
     * chain temp index varbinds together
     */
    var_linkIndex.next_variable = NULL;


    DEBUGMSGTL(("verbose:linkTable:linkTable_index_from_oid", "called\n"));

    /*
     * parse the oid into the individual index components
     */
    err = parse_oid_indexes(oid_idx->oids, oid_idx->len, &var_linkIndex);
    if (err == SNMP_ERR_NOERROR) {
        /*
         * copy out values
         */
        mib_idx->linkIndex = *((u_long *) var_linkIndex.val.string);


    }

    /*
     * parsing may have allocated memory. free it.
     */
    snmp_reset_var_buffers(&var_linkIndex);

    return err;
}                               /* linkTable_index_from_oid */


/*
 *********************************************************************
 * @internal
 * allocate resources for a linkTable_rowreq_ctx
 */
linkTable_rowreq_ctx *
linkTable_allocate_rowreq_ctx(void)
{
    linkTable_rowreq_ctx *rowreq_ctx =
        SNMP_MALLOC_TYPEDEF(linkTable_rowreq_ctx);

    DEBUGMSGTL(("internal:linkTable:linkTable_allocate_rowreq_ctx",
                "called\n"));

    if (NULL == rowreq_ctx) {
        snmp_log(LOG_ERR, "Couldn't allocate memory for a "
                 "linkTable_rowreq_ctx.\n");
        return NULL;
    }

    rowreq_ctx->oid_idx.oids = rowreq_ctx->oid_tmp;

    rowreq_ctx->linkTable_data_list = NULL;


    return rowreq_ctx;
}                               /* linkTable_allocate_rowreq_ctx */

/*
 * @internal
 * release resources for a linkTable_rowreq_ctx
 */
void
linkTable_release_rowreq_ctx(linkTable_rowreq_ctx * rowreq_ctx)
{
    DEBUGMSGTL(("internal:linkTable:linkTable_release_rowreq_ctx",
                "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);


    /*
     * free index oid pointer
     */
    if (rowreq_ctx->oid_idx.oids != rowreq_ctx->oid_tmp)
        free(rowreq_ctx->oid_idx.oids);

    SNMP_FREE(rowreq_ctx);
}                               /* linkTable_release_rowreq_ctx */

/**
 * @internal
 * wrapper
 */
static int
_mfd_linkTable_pre_request(netsnmp_mib_handler *handler,
                           netsnmp_handler_registration *reginfo,
                           netsnmp_agent_request_info *agtreq_info,
                           netsnmp_request_info *requests)
{
    int             rc;

    DEBUGMSGTL(("internal:linkTable:_mfd_linkTable_pre_request",
                "called\n"));

    if (1 != netsnmp_row_merge_status_first(reginfo, agtreq_info)) {
        DEBUGMSGTL(("internal:linkTable",
                    "skipping additional pre_request\n"));
        return SNMP_ERR_NOERROR;
    }

    rc = linkTable_pre_request(linkTable_if_ctx.user_ctx);
    if (MFD_SUCCESS != rc) {
        /*
         * nothing we can do about it but log it
         */
        DEBUGMSGTL(("linkTable", "error %d from "
                    "linkTable_pre_request\n", rc));
        netsnmp_request_set_error_all(requests, SNMP_VALIDATE_ERR(rc));
    }

    return SNMP_ERR_NOERROR;
}                               /* _mfd_linkTable_pre_request */

/**
 * @internal
 * wrapper
 */
static int
_mfd_linkTable_post_request(netsnmp_mib_handler *handler,
                            netsnmp_handler_registration *reginfo,
                            netsnmp_agent_request_info *agtreq_info,
                            netsnmp_request_info *requests)
{
    linkTable_rowreq_ctx *rowreq_ctx = (linkTable_rowreq_ctx *)
        netsnmp_container_table_row_extract(requests);
    int             rc, packet_rc;

    DEBUGMSGTL(("internal:linkTable:_mfd_linkTable_post_request",
                "called\n"));

    /*
     * release row context, if deleted
     */
    if (rowreq_ctx && (rowreq_ctx->rowreq_flags & MFD_ROW_DELETED))
        linkTable_release_rowreq_ctx(rowreq_ctx);

    /*
     * wait for last call before calling user
     */
    if (1 != netsnmp_row_merge_status_last(reginfo, agtreq_info)) {
        DEBUGMSGTL(("internal:linkTable",
                    "waiting for last post_request\n"));
        return SNMP_ERR_NOERROR;
    }

    packet_rc = netsnmp_check_all_requests_error(agtreq_info->asp, 0);
    rc = linkTable_post_request(linkTable_if_ctx.user_ctx, packet_rc);
    if (MFD_SUCCESS != rc) {
        /*
         * nothing we can do about it but log it
         */
        DEBUGMSGTL(("linkTable", "error %d from "
                    "linkTable_post_request\n", rc));
    }

    return SNMP_ERR_NOERROR;
}                               /* _mfd_linkTable_post_request */

/**
 * @internal
 * wrapper
 */
static int
_mfd_linkTable_object_lookup(netsnmp_mib_handler *handler,
                             netsnmp_handler_registration *reginfo,
                             netsnmp_agent_request_info *agtreq_info,
                             netsnmp_request_info *requests)
{
    int             rc = SNMP_ERR_NOERROR;
    linkTable_rowreq_ctx *rowreq_ctx = (linkTable_rowreq_ctx *)
        netsnmp_container_table_row_extract(requests);

    DEBUGMSGTL(("internal:linkTable:_mfd_linkTable_object_lookup",
                "called\n"));

    /*
     * get our context from mfd
     * linkTable_interface_ctx *if_ctx =
     *             (linkTable_interface_ctx *)reginfo->my_reg_void;
     */

    if (NULL == rowreq_ctx) {
        rc = SNMP_ERR_NOCREATION;
    }

    if (MFD_SUCCESS != rc)
        netsnmp_request_set_error_all(requests, rc);
    else
        linkTable_row_prep(rowreq_ctx);

    return SNMP_VALIDATE_ERR(rc);
}                               /* _mfd_linkTable_object_lookup */

/***********************************************************************
 *
 * GET processing
 *
 ***********************************************************************/
/*
 * @internal
 * Retrieve the value for a particular column
 */
NETSNMP_STATIC_INLINE int
_linkTable_get_column(linkTable_rowreq_ctx * rowreq_ctx,
                      netsnmp_variable_list * var, int column)
{
    int             rc = SNMPERR_SUCCESS;

    DEBUGMSGTL(("internal:linkTable:_mfd_linkTable_get_column",
                "called for %d\n", column));


    netsnmp_assert(NULL != rowreq_ctx);

    switch (column) {

        /*
         * linkID(2)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_LINKID:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = linkID_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * slc(3)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_SLC:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = slc_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * corSet(4)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_CORSET:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = corSet_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * txPort(5)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_TXPORT:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = txPort_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * txChan(6)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_TXCHAN:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = txChan_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * txBran(7)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_TXBRAN:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = txBran_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * txBrMgr(8)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_TXBRMGR:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = txBrMgr_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * corBrMgr(9)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_CORBRMGR:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = corBrMgr_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * corBrCon(10)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_CORBRCON:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = corBrCon_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * protocol(11)/DisplayString/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/H 
         */
    case COLUMN_PROTOCOL:
        var->type = ASN_OCTET_STR;
        rc = protocol_get(rowreq_ctx, (char **) &var->val.string,
                          &var->val_len);
        break;

        /*
         * time(12)/TimeStamp/ASN_TIMETICKS/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_TIME:
        var->val_len = sizeof(u_long);
        var->type = ASN_TIMETICKS;
        rc = time_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * txISUP(13)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_TXISUP:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = txISUP_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * rxISUP(14)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_RXISUP:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = rxISUP_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * txSCCP(15)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_TXSCCP:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = txSCCP_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * rxSCCP(16)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_RXSCCP:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = rxSCCP_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * txSNMM(17)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_TXSNMM:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = txSNMM_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * rxSNMM(18)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_RXSNMM:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = rxSNMM_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * txFISU(19)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_TXFISU:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = txFISU_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * rxFISU(20)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_RXFISU:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = rxFISU_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * txOther(21)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_TXOTHER:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = txOther_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * rxOther(22)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_RXOTHER:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = rxOther_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * txErr(23)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_TXERR:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = txErr_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * rxErr(24)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_RXERR:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = rxErr_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * txErrRate(25)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_TXERRRATE:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = txErrRate_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * rxErrRate(26)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_RXERRRATE:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = rxErrRate_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * unitID(27)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_UNITID:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = unitID_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * linkSet(28)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_LINKSET:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = linkSet_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * originCLLI(29)/DisplayString/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/H 
         */
    case COLUMN_ORIGINCLLI:
        var->type = ASN_OCTET_STR;
        rc = originCLLI_get(rowreq_ctx, (char **) &var->val.string,
                            &var->val_len);
        break;

        /*
         * destinCLLI(30)/DisplayString/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/H 
         */
    case COLUMN_DESTINCLLI:
        var->type = ASN_OCTET_STR;
        rc = destinCLLI_get(rowreq_ctx, (char **) &var->val.string,
                            &var->val_len);
        break;

        /*
         * originPtCd(31)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_ORIGINPTCD:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = originPtCd_get(rowreq_ctx, (u_long *) var->val.string);
        break;

        /*
         * destinPtCd(32)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_DESTINPTCD:
        var->val_len = sizeof(u_long);
        var->type = ASN_UNSIGNED;
        rc = destinPtCd_get(rowreq_ctx, (u_long *) var->val.string);
        break;

    default:
        if (LINKTABLE_MIN_COL <= column && column <= LINKTABLE_MAX_COL) {
            DEBUGMSGTL(("internal:linkTable:_mfd_linkTable_get_column",
                        "assume column %d is reserved\n", column));
            rc = MFD_SKIP;
        } else {
            snmp_log(LOG_ERR,
                     "unknown column %d in _linkTable_get_column\n",
                     column);
        }
        break;
    }

    return rc;
}                               /* _linkTable_get_column */

int
_mfd_linkTable_get_values(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info *agtreq_info,
                          netsnmp_request_info *requests)
{
    linkTable_rowreq_ctx *rowreq_ctx = (linkTable_rowreq_ctx *)
        netsnmp_container_table_row_extract(requests);
    netsnmp_table_request_info *tri;
    u_char         *old_string;
    void            (*dataFreeHook) (void *);
    int             rc;

    DEBUGMSGTL(("internal:linkTable:_mfd_linkTable_get_values",
                "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    for (; requests; requests = requests->next) {
        /*
         * save old pointer, so we can free it if replaced
         */
        old_string = requests->requestvb->val.string;
        dataFreeHook = requests->requestvb->dataFreeHook;
        if (NULL == requests->requestvb->val.string) {
            requests->requestvb->val.string = requests->requestvb->buf;
            requests->requestvb->val_len =
                sizeof(requests->requestvb->buf);
        } else if (requests->requestvb->buf ==
                   requests->requestvb->val.string) {
            if (requests->requestvb->val_len !=
                sizeof(requests->requestvb->buf))
                requests->requestvb->val_len =
                    sizeof(requests->requestvb->buf);
        }

        /*
         * get column data
         */
        tri = netsnmp_extract_table_info(requests);
        if (NULL == tri)
            continue;

        rc = _linkTable_get_column(rowreq_ctx, requests->requestvb,
                                   tri->colnum);
        if (rc) {
            if (MFD_SKIP == rc) {
                requests->requestvb->type = SNMP_NOSUCHINSTANCE;
                rc = SNMP_ERR_NOERROR;
            }
        } else if (NULL == requests->requestvb->val.string) {
            snmp_log(LOG_ERR, "NULL varbind data pointer!\n");
            rc = SNMP_ERR_GENERR;
        }
        if (rc)
            netsnmp_request_set_error(requests, SNMP_VALIDATE_ERR(rc));

        /*
         * if the buffer wasn't used previously for the old data (i.e. it
         * was allcoated memory)  and the get routine replaced the pointer,
         * we need to free the previous pointer.
         */
        if (old_string && (old_string != requests->requestvb->buf) &&
            (requests->requestvb->val.string != old_string)) {
            if (dataFreeHook)
                (*dataFreeHook) (old_string);
            else
                free(old_string);
        }
    }                           /* for results */

    return SNMP_ERR_NOERROR;
}                               /* _mfd_linkTable_get_values */

/***********************************************************************
 *
 * SET processing
 *
 ***********************************************************************/

/*
 * SET PROCESSING NOT APPLICABLE (per MIB or user setting)
 */
/***********************************************************************
 *
 * DATA ACCESS
 *
 ***********************************************************************/
static void     _container_free(netsnmp_container * container);

/**
 * @internal
 */
static int
_cache_load(netsnmp_cache * cache, void *vmagic)
{
    DEBUGMSGTL(("internal:linkTable:_cache_load", "called\n"));

    if ((NULL == cache) || (NULL == cache->magic)) {
        snmp_log(LOG_ERR, "invalid cache for linkTable_cache_load\n");
        return -1;
    }

    /** should only be called for an invalid or expired cache */
    netsnmp_assert((0 == cache->valid) || (1 == cache->expired));

    /*
     * call user code
     */
    return linkTable_container_load((netsnmp_container *) cache->magic);
}                               /* _cache_load */

/**
 * @internal
 */
static void
_cache_free(netsnmp_cache * cache, void *magic)
{
    netsnmp_container *container;

    DEBUGMSGTL(("internal:linkTable:_cache_free", "called\n"));

    if ((NULL == cache) || (NULL == cache->magic)) {
        snmp_log(LOG_ERR, "invalid cache in linkTable_cache_free\n");
        return;
    }

    container = (netsnmp_container *) cache->magic;

    _container_free(container);
}                               /* _cache_free */

/**
 * @internal
 */
static void
_container_item_free(linkTable_rowreq_ctx * rowreq_ctx, void *context)
{
    DEBUGMSGTL(("internal:linkTable:_container_item_free", "called\n"));

    if (NULL == rowreq_ctx)
        return;

    linkTable_release_rowreq_ctx(rowreq_ctx);
}                               /* _container_item_free */

/**
 * @internal
 */
static void
_container_free(netsnmp_container * container)
{
    DEBUGMSGTL(("internal:linkTable:_container_free", "called\n"));

    if (NULL == container) {
        snmp_log(LOG_ERR,
                 "invalid container in linkTable_container_free\n");
        return;
    }

    /*
     * call user code
     */
    linkTable_container_free(container);

    /*
     * free all items. inefficient, but easy.
     */
    CONTAINER_CLEAR(container,
                    (netsnmp_container_obj_func *) _container_item_free,
                    NULL);
}                               /* _container_free */

/**
 * @internal
 * initialize the container with functions or wrappers
 */
void
_linkTable_container_init(linkTable_interface_ctx * if_ctx)
{
    DEBUGMSGTL(("internal:linkTable:_linkTable_container_init",
                "called\n"));

    /*
     * cache init
     */
    if_ctx->cache = netsnmp_cache_create(30,    /* timeout in seconds */
                                         _cache_load, _cache_free,
                                         linkTable_oid,
                                         linkTable_oid_size);

    if (NULL == if_ctx->cache) {
        snmp_log(LOG_ERR, "error creating cache for linkTable\n");
        return;
    }

    if_ctx->cache->flags = NETSNMP_CACHE_DONT_INVALIDATE_ON_SET;

    linkTable_container_init(&if_ctx->container, if_ctx->cache);
    if (NULL == if_ctx->container)
        if_ctx->container =
            netsnmp_container_find("linkTable:table_container");
    if (NULL == if_ctx->container) {
        snmp_log(LOG_ERR, "error creating container in "
                 "linkTable_container_init\n");
        return;
    }

    if (NULL != if_ctx->cache)
        if_ctx->cache->magic = (void *) if_ctx->container;
}                               /* _linkTable_container_init */

/**
 * @internal
 * shutdown the container with functions or wrappers
 */
void
_linkTable_container_shutdown(linkTable_interface_ctx * if_ctx)
{
    DEBUGMSGTL(("internal:linkTable:_linkTable_container_shutdown",
                "called\n"));

    linkTable_container_shutdown(if_ctx->container);

    _container_free(if_ctx->container);

}                               /* _linkTable_container_shutdown */


linkTable_rowreq_ctx *
linkTable_row_find_by_mib_index(linkTable_mib_index * mib_idx)
{
    linkTable_rowreq_ctx *rowreq_ctx;
    oid             oid_tmp[MAX_OID_LEN];
    netsnmp_index   oid_idx;
    int             rc;

    /*
     * set up storage for OID
     */
    oid_idx.oids = oid_tmp;
    oid_idx.len = sizeof(oid_tmp) / sizeof(oid);

    /*
     * convert
     */
    rc = linkTable_index_to_oid(&oid_idx, mib_idx);
    if (MFD_SUCCESS != rc)
        return NULL;

    rowreq_ctx =
        (linkTable_rowreq_ctx *) CONTAINER_FIND(linkTable_if_ctx.container,
                                                &oid_idx);

    return rowreq_ctx;
}
