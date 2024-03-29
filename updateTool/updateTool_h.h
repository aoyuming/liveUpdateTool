

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Jul 08 11:00:52 2019
 */
/* Compiler settings for updateTool.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __updateTool_h_h__
#define __updateTool_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IupdateTool_FWD_DEFINED__
#define __IupdateTool_FWD_DEFINED__
typedef interface IupdateTool IupdateTool;

#endif 	/* __IupdateTool_FWD_DEFINED__ */


#ifndef __updateTool_FWD_DEFINED__
#define __updateTool_FWD_DEFINED__

#ifdef __cplusplus
typedef class updateTool updateTool;
#else
typedef struct updateTool updateTool;
#endif /* __cplusplus */

#endif 	/* __updateTool_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __updateTool_LIBRARY_DEFINED__
#define __updateTool_LIBRARY_DEFINED__

/* library updateTool */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_updateTool;

#ifndef __IupdateTool_DISPINTERFACE_DEFINED__
#define __IupdateTool_DISPINTERFACE_DEFINED__

/* dispinterface IupdateTool */
/* [uuid] */ 


EXTERN_C const IID DIID_IupdateTool;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00FCB98D-79D4-4009-A0F6-4FAA6EA0230F")
    IupdateTool : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IupdateToolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IupdateTool * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IupdateTool * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IupdateTool * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IupdateTool * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IupdateTool * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IupdateTool * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IupdateTool * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IupdateToolVtbl;

    interface IupdateTool
    {
        CONST_VTBL struct IupdateToolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IupdateTool_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IupdateTool_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IupdateTool_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IupdateTool_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IupdateTool_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IupdateTool_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IupdateTool_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IupdateTool_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_updateTool;

#ifdef __cplusplus

class DECLSPEC_UUID("3BF5B980-4E41-4A7A-8C49-8C0ED4C16034")
updateTool;
#endif
#endif /* __updateTool_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


