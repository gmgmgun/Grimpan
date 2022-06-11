
// ChildView.h : interface of the CChildView class
//


#pragma once
#include"Figure.h"
#include "gdiplus.h"
#include <memory>

// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:

	std::shared_ptr<Figure> m_figure;
	std::shared_ptr<Gdiplus::Bitmap> m_canvas;
	std::shared_ptr<CList<Figure, Figure&>> m_figureList;
	Gdiplus::Point m_point;
	afx_msg void OnFileExit();
	afx_msg void OnDraw();
	afx_msg void OnDrawPot();
	afx_msg void OnDrawLine();
	afx_msg void OnDrawRect();
	afx_msg void OnDrawEllipse();
	afx_msg void OnDrawText();
	afx_msg void OnDrawClear();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDrawCanvas();
	void SetInvalidateArea(CPoint &startPoint, CPoint &endPoint);
	void SaveFigure(Gdiplus::Point startPoint, Gdiplus::Point endPoint);
	void LoadFigure(Gdiplus::Point &startPoint, Gdiplus::Point &endPoint);
	//CList<Figure, Figure&> m_figureList;
	int m_mode;
	int m_ThicknessOfPen;
	bool m_IsMouseMove;
	bool m_IsBtnDown;
	bool m_IsSetStart;
	HDC m_dc;
	void InitCanvas();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

