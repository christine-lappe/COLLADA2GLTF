/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEFROMSUBDIVFACE_H__
#define __MayaDM_CURVEFROMSUBDIVFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveFromSubdiv.h"
namespace MayaDM
{
class CurveFromSubdivFace : public CurveFromSubdiv
{
public:
public:
	CurveFromSubdivFace(FILE* file,const std::string& name,const std::string& parent=""):CurveFromSubdiv(file, name, parent, "curveFromSubdivFace"){}
	virtual ~CurveFromSubdivFace(){}
	void setFaceIndexL(size_t fil_i,int fil)
	{
		if(fil == 0) return;
		fprintf(mFile,"setAttr \".fil[%i]\" %i;\n", fil_i,fil);

	}
	void setFaceIndexL(size_t fil_start,size_t fil_end,int* fil)
	{
		fprintf(mFile,"setAttr \".fil[%i:%i]\" ", fil_start,fil_end);
		size_t size = (fil_end-fil_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",fil[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startFaceIndexL(size_t fil_start,size_t fil_end)
	{
		fprintf(mFile,"setAttr \".fil[%i:%i]\"",fil_start,fil_end);

	}
	void appendFaceIndexL(int fil)
	{
		fprintf(mFile," %i",fil);

	}
	void endFaceIndexL()
	{
		fprintf(mFile,";\n");

	}
	void setFaceIndexR(size_t fir_i,int fir)
	{
		if(fir == 0) return;
		fprintf(mFile,"setAttr \".fir[%i]\" %i;\n", fir_i,fir);

	}
	void setFaceIndexR(size_t fir_start,size_t fir_end,int* fir)
	{
		fprintf(mFile,"setAttr \".fir[%i:%i]\" ", fir_start,fir_end);
		size_t size = (fir_end-fir_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",fir[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startFaceIndexR(size_t fir_start,size_t fir_end)
	{
		fprintf(mFile,"setAttr \".fir[%i:%i]\"",fir_start,fir_end);

	}
	void appendFaceIndexR(int fir)
	{
		fprintf(mFile," %i",fir);

	}
	void endFaceIndexR()
	{
		fprintf(mFile,";\n");

	}
	void getFaceIndexL(size_t fil_i)
	{
		fprintf(mFile,"\"%s.fil[%i]\"",mName.c_str(),fil_i);

	}
	void getFaceIndexR(size_t fir_i)
	{
		fprintf(mFile,"\"%s.fir[%i]\"",mName.c_str(),fir_i);

	}
protected:
	CurveFromSubdivFace(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CurveFromSubdiv(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMSUBDIVFACE_H__
