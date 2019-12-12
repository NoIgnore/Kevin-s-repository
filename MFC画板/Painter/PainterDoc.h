// PainterDoc.h : interface of the CPainterDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PAINTERDOC_H__51FFE67C_066D_4AE9_9DA7_7110DE1E0541__INCLUDED_)
#define AFX_PAINTERDOC_H__51FFE67C_066D_4AE9_9DA7_7110DE1E0541__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Shape.h"
#include <vector>
using namespace std;//vector��Ҫ

class CPainterDoc : public CDocument
{
//�洢
protected:
	vector<CShape*> shapes;//�洢�Ѿ����õ���״
	//ʹ�û���ָ����ʵ�ֶ�̬��
public:
	//����ĩβ��״���յ㡣����ڼ�����״ʱ�Ѿ�����
	void setEndPoint(CPoint point){shapes.back()->setEndPoint(point);}
	//����ָ����״��ָ��
	void push_back(CShape* p_shape){shapes.push_back(p_shape);}
	bool empty(){return shapes.empty();}
	size_t size(){return shapes.size(); }
	void pop_back(){shapes.pop_back(); }
	//���洢����״ȫ������
	void draw(CDC* pDC);
	//�����������
	void clear();

protected: // create from serialization only
	CPainterDoc();
	DECLARE_DYNCREATE(CPainterDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPainterDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPainterDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPainterDoc)
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINTERDOC_H__51FFE67C_066D_4AE9_9DA7_7110DE1E0541__INCLUDED_)
