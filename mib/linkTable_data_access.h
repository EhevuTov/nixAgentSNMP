/*
 * Note: this file originally auto-generated by mib2c using
 *       version $ of $
 *
 * $Id:$
 */
#ifndef LINKTABLE_DATA_ACCESS_H
#define LINKTABLE_DATA_ACCESS_H

#ifdef __cplusplus
extern          "C" {
#endif


    /*
     *********************************************************************
     * function declarations
     */

    /*
     *********************************************************************
     * Table declarations
     */
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


    int             linkTable_init_data(linkTable_registration *
                                        linkTable_reg);


    /*
     * TODO:180:o: Review linkTable cache timeout.
     * The number of seconds before the cache times out
     */
#define LINKTABLE_CACHE_TIMEOUT   60

    void            linkTable_container_init(netsnmp_container **
                                             container_ptr_ptr,
                                             netsnmp_cache * cache);
    void            linkTable_container_shutdown(netsnmp_container *
                                                 container_ptr);

    int             linkTable_container_load(netsnmp_container *
                                             container);
    void            linkTable_container_free(netsnmp_container *
                                             container);

    int             linkTable_cache_load(netsnmp_container * container);
    void            linkTable_cache_free(netsnmp_container * container);

    /*
     ***************************************************
     ***             START EXAMPLE CODE              ***
     ***---------------------------------------------***/
    /*
     *********************************************************************
     * Since we have no idea how you really access your data, we'll go with
     * a worst case example: a flat text file.
     */
#define MAX_LINE_SIZE 256
    /*
     ***---------------------------------------------***
     ***              END  EXAMPLE CODE              ***
     ***************************************************/
    int             linkTable_row_prep(linkTable_rowreq_ctx * rowreq_ctx);



#ifdef __cplusplus
}
#endif
#endif                          /* LINKTABLE_DATA_ACCESS_H */
