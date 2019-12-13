// PainterDoc.cpp : implementation of the CPainterDoc class
//

#include "stdafx.h"
#include "Painter.h"

#include "PainterDoc.h"

//��״
#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"


#include <fstream>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPainterDoc

IMPLEMENT_DYNCREATE(CPainterDoc, CDocument)

BEGIN_MESSAGE_MAP(CPainterDoc, CDocument)
	//{{AFX_MSG_MAP(CPainterDoc)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPainterDoc construction/destruction

CPainterDoc::CPainterDoc()
{
	// TODO: add one-time construction code here

}
//@funcName <CPainterDoc::draw>
//@statement <����shapes���ݻ�������ͼ��>
//@parameter <�������豸������:CDC>
void CPainterDoc::draw(CDC* pDC)
{
	for(size_t i=0;i<shapes.size();i++)
	{
		shapes[i]->draw(pDC);
	}
}

CPainterDoc::~CPainterDoc()
{
	for(size_t i = 0; i < shapes.size(); i++)
	{
		delete shapes[i];
	}
}
//@funcName <clear>
//@statement <�����������>
void CPainterDoc::clear()
{
	while(!shapes.empty())
	{
		delete shapes[0];
		shapes.erase(shapes.begin());//ɾ�����ָ��
	}
	
}

BOOL CPainterDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPainterDoc serialization

void CPainterDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPainterDoc diagnostics

#ifdef _DEBUG
void CPainterDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPainterDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPainterDoc commands

void CPainterDoc::OnFileSave() 
{
	// TODO: Add your command handler code here

	//ʹ���Դ��ı���Ի����ȡ·��
	CFileDialog saveDlg(false,TEXT("painter"),TEXT("δ����"),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,".painter");
	saveDlg.DoModal();
	CString pathName=saveDlg.GetPathName();
	
	if(pathName=="") return;//���ֱ�ӹص�����


	//���浽�ļ���
	CStdioFile fout;
	CString buffer;//д�ļ�������
	if(!fout.Open(pathName,CFile::modeCreate|CFile::modeWrite))
		return;//�����ʧ�ܾͷ���
	for(size_t i=0;i<size();i++)
	{
		buffer.Format("%d %d %d %d %d %d %d",
				shapes[i]->getShapeType(),
				shapes[i]->getBorderColor(),
				shapes[i]->getFillColor(),
				shapes[i]->getStartPoint().x,
				shapes[i]->getStartPoint().y,
				shapes[i]->getEndPoint().x,
				shapes[i]->getEndPoint().y
				);
		if(i!=size()-1)
			buffer+="\n";//���һ�в��ӻ���
		fout.WriteString(buffer);
	}
	fout.Close();
	
}

void CPainterDoc::OnFileOpen() 
{
	// TODO: Add your command handler code here
	//ʹ���Դ��ĶԻ����ȡ·��
	CFileDialog openDlg(true,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,NULL);
	openDlg.DoModal();
	CString pathName=openDlg.GetPathName();
	

	if(pathName=="") return;//���ֱ�ӹص�����
	//��ȡ�ļ�
	using namespace std;
	ifstream fin;

	COLORREF borderColor;//�߿���ɫ
	COLORREF fillColor;//�����ɫ
	CPoint startPoint;//�������
	CPoint endPoint;//�����յ�
	enum shapeType{UNSURE,LINE,RECTANGLE,ELLIPSE};//��״����
	int type;//��״

	CShape *newShape=NULL;
	
	clear();//��ջ���
	
	fin.open(pathName);
	while(!fin.eof())
	{
		fin>>type
			>>borderColor
			>>fillColor
			>>startPoint.x
			>>startPoint.y
			>>endPoint.x
			>>endPoint.y;
		switch(type)
		{
		case LINE://ֱ��
			newShape=new CLine(borderColor,fillColor,startPoint,endPoint);
			
			break;
		case RECTANGLE://����
			newShape=new CRectangle(borderColor,fillColor,startPoint,endPoint);
			
			break;
		case ELLIPSE:
			newShape=new CEllipse(borderColor,fillColor,startPoint,endPoint);
			
			break;
		}
		push_back(newShape);//�������״
	
	}
	fin.close();
}


