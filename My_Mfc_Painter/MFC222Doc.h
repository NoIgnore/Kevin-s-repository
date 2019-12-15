
// MFC222Doc.h: CMFC222Doc 类的接口
//


#pragma once
#include"CLayer.h"
#include <vector>
using namespace std;

class CMFC222Doc : public CDocument
{
protected: // 仅从序列化创建
	CMFC222Doc() ;
	DECLARE_DYNCREATE(CMFC222Doc)

// 特性
public:

// 操作
public:
	int numberdoc = 0;
	int numberdoc2 = 1;
	vector<CLayer*> shapes;
	void setEndPoint(CPoint point) { shapes.back()->setEndPoint(point); }
	//新增指向形状的指针
	void push_back(CLayer* p_shape) { shapes.push_back(p_shape); }
	bool empty() { return shapes.empty(); }
	size_t size() { return shapes.size(); }
	void pop_back() { shapes.pop_back(); }
	//将存储的形状全画出来
	void draw(CDC* pDC);



// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMFC222Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSaveAs();
	UINT m_nindex2;
	afx_msg void OnDrawArrow();
	void SelectLayer(UINT nFlags, CPoint point);
	void SelectEnd(UINT nFlags, CPoint point);
};
