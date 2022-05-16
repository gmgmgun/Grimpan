
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "GrimpanTest.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define SIZE 10

//CChildView
CChildView::CChildView()
{
	int m_mode = 0;
	int m_ThicknessOfPen = 0;
	bool m_IsMouseMove = false;
	bool m_IsBtnDown = false;
	bool m_IsSetStart = false;
}

CChildView::~CChildView()
{

}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_DRAW_POT, OnDrawPot)
	ON_COMMAND(ID_DRAW_LINE, OnDrawLine)
	ON_COMMAND(ID_DRAW_RECT, OnDrawRect)
	ON_COMMAND(ID_DRAW_ELLIPSE,OnDrawEllipse)
	ON_COMMAND(ID_DRAW_TEXT, OnDrawText)
	ON_COMMAND(ID_DRAW_CLEAR, OnDrawClear)
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	OnDraw();
//Gdiplus:Graphics subG(dc.GetSafeHdc());

	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
}

void CChildView::OnDraw()
{
	//CWnd * pWnd = AfxGetMainWnd();
	//HWND hWnd = pWnd->m_hWnd;
	//HDC hDC = ::GetDC(hWnd);
	//CPaintDC dc(this);
   // Gdiplus::Graphics g(dc.GetSafeHdc());
	if (m_canvas == nullptr)
		return;
	if (m_figure == nullptr)
		return;
	CPaintDC dc(this); // device context for painting
	
	Gdiplus::Graphics mainG(dc.GetSafeHdc());
	//mainG.DrawImage(m_canvas.get(), 0, 0, m_canvas->GetWidth(), m_canvas->GetHeight());

	//Gdiplus::Graphics g(m_canvas.get());
	//Gdiplus::Graphics g(hDC);
	Gdiplus::Pen pen(Gdiplus::Color(255, 255, 0, 0), 20);
	mainG.DrawLine(&pen, m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X, m_figure->endPoint.Y);
	//
	/*
	Figure m_figure2;
	POSITION pos = m_figureList->GetHeadPosition();
	for (int i = 1; i <= m_figureList->GetCount(); i++)
	{
	case 1:
		break;
	case 2:
		//memG.DrawLine(&pen, m_figure->startPoint.X-100, m_figure->startPoint.Y+100, m_figure->endPoint.X+100, m_figure->endPoint.Y-100);
		memG.DrawLine(&pen, m_figure->startPoint.X, m_figure->startPoint.Y , m_figure->endPoint.X , m_figure->endPoint.Y );
		break;
	case 3:
		memG.DrawRectangle(&pen, m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X - m_figure->startPoint.X, m_figure->endPoint.Y - m_figure->startPoint.Y);
		break;
	case 4:
		memG.DrawEllipse(&pen, m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X, m_figure->endPoint.Y);
		break;
	case 5:
		Gdiplus::FontFamily fontFamily(L"Times New Roman");
		Gdiplus::Font font(&fontFamily, 24, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
		Gdiplus::PointF pointF(m_figure->endPoint.X, m_figure->endPoint.Y);
		Gdiplus::SolidBrush solidBrush(Gdiplus::Color(255, 0, 0, 255));
		memG.DrawString(L"TEXT", -1, &font, pointF, &solidBrush);
		break;
	}
	*/
	//if (m_IsMouseMove == true)
	//{
	//	Gdiplus::SolidBrush mySolidBrush(Gdiplus::Color(255, 255, 255, 255));
	//	Gdiplus::Rect rt(m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X - m_figure->startPoint.X, m_figure->endPoint.Y - m_figure->startPoint.Y);
	//	mainG.FillRectangle(&mySolidBrush,rt);
	//	HDC h_dc = ::GetDC(m_hWnd);
	//	BitBlt(h_dc, m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X - m_figure->startPoint.X, m_figure->endPoint.Y - m_figure->startPoint.Y, m_dc, 0, 0, SRCCOPY);

	//	::ReleaseDC(m_hWnd, h_dc);         // 
	//	::ReleaseDC(m_hWnd, m_dc);  // 

	//}
	//while (!m_figureList->IsEmpty())
	//{
	//	Gdiplus::Point p1;
	//	Gdiplus::Point p2;
	//	p1 = m_figureList->GetTail().startPoint;
	//	p2 = m_figureList->GetTail().endPoint;
	//	mainG.DrawLine(&pen,p1.X,p1.Y,p2.X,p2.Y);
	//	//POSITION pos = m_figureList->GetTailPosition();
	//	//m_figureList->RemoveAt(pos);
	//}
	
	//memg
	//switch (m_mode)
	//{
	//case 1:
	//	break;
	//case 2:
	//	mainG.DrawLine(&pen, m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X, m_figure->endPoint.Y);
	//	break;
	//case 3:
	//	mainG.DrawRectangle(&pen, m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X - m_figure->startPoint.X, m_figure->endPoint.Y - m_figure->startPoint.Y);
	//	break;
	//case 4:
	//	mainG.DrawEllipse(&pen, m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X, m_figure->endPoint.Y);
	//	break;
	//case 5:
	//	Gdiplus::FontFamily fontFamily(L"Times New Roman");
	//	Gdiplus::Font font(&fontFamily, 24, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
	//	Gdiplus::PointF pointF(m_figure->endPoint.X, m_figure->endPoint.Y);
	//	Gdiplus::SolidBrush solidBrush(Gdiplus::Color(255, 0, 0, 255));

	//	mainG.DrawString(L"TEXT", -1, &font, pointF, &solidBrush);
	//	break;
	//}
	//::ReleaseDC(hWnd, hDC);
}

void CChildView::OnDrawPot()
{
	m_mode = 1;
	//InvalidateRect();
}


void CChildView::OnDrawLine()
{
	m_mode = 2;
	//InvalidateRect();
}

void CChildView::OnDrawRect()
{
	m_mode = 3;
	//InvalidateRect();
}

void CChildView::OnDrawEllipse()
{
	m_mode = 4;
	//InvalidateRect();
}

void CChildView::OnDrawText()
{
	m_mode = 5;
}

void CChildView::OnDrawClear()
{
	m_mode = 0;
	Invalidate(TRUE);
	UpdateWindow();
}
//RangedCommand

void CChildView::OnFileExit()
{
	AfxGetMainWnd()->PostMessage(WM_CLOSE);
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{

	m_dc = ::GetDC(m_hWnd);
	//if (m_figureList->GetCount() != 0)
	//{
	//	Invalidate(FALSE);
	//}
	m_IsBtnDown = true;
	//
	m_point.X = point.x;
	m_point.Y = point.y;
	// 
	m_figure = std::make_shared<Figure>();

	//
	m_IsSetStart = true;
	m_figure->SetPoint(m_point, m_IsSetStart);
	//

	//

	CPoint invaldateStartPoint;
	CPoint invaldateEndPoint;
	//
	//SetInvalidateArea(invaldateStartPoint, invaldateEndPoint);
	//


	CRect rt(invaldateStartPoint, invaldateEndPoint);
	//CRect rt(endPoint, startPoint);
	//InvalidateRect(rt, FALSE);
	//CRect rt(m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X - m_figure->startPoint.X, m_figure->endPoint.Y - m_figure->startPoint.Y);
	//InvalidateRect(rt,FALSE);
	//Invalidate(FALSE);
	CWnd::OnLButtonDown(nFlags, point);
}

void CChildView::SetInvalidateArea(CPoint &startPoint, CPoint &endPoint)
{
	int offset = 50;
	startPoint.x = m_figure->startPoint.X;
	startPoint.y = m_figure->startPoint.Y;
	endPoint.x = m_figure->endPoint.X;
	endPoint.y = m_figure->endPoint.Y;
	if (startPoint.x > endPoint.x)
	{
		startPoint.x += offset;
		endPoint.x -= offset;
	}
	else if (startPoint.x < endPoint.x)
	{
		startPoint.x -= offset;
		endPoint.x += offset;
	}
	if (startPoint.y > endPoint.y)
	{
		startPoint.y += offset;
		endPoint.y -= offset;
	}
	else if (startPoint.y < endPoint.y)
	{
		startPoint.y -= offset;
		endPoint.y += offset;
	}
}

void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	m_IsMouseMove = true;
	//CRect rt(m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X - m_figure->startPoint.X, m_figure->endPoint.Y - m_figure->startPoint.Y);
	//InvalidateRect(rt, FALSE);
	if (m_IsBtnDown == true) {
		m_IsMouseMove = true;
		//UpdateWindow();
		if (m_figure == NULL)
			return;
		m_point.X = point.x;
		m_point.Y = point.y;
		m_IsSetStart = false;
		m_figure->SetPoint(m_point, m_IsSetStart);
		//CPoint startPoint;
		//CPoint endPoint;
		//int offset = 100;
		//startPoint.x = m_figure->startPoint.X;
		//startPoint.y = m_figure->startPoint.Y;
		//endPoint.x = m_figure->endPoint.X;
		//endPoint.y = m_figure->endPoint.Y;
		//if (startPoint.x > endPoint.x)
		//{
		//	startPoint.x += offset;
		//	endPoint.x -= offset;
		//}
		//else if (startPoint.x < endPoint.x)
		//{
		//	startPoint.x -= offset;
		//	endPoint.x += offset;
		//}
		//if (startPoint.y > endPoint.y)
		//{
		//	startPoint.y += offset;
		//	endPoint.y -= offset;
		//}
		//else if (startPoint.y < endPoint.y)
		//{
		//	startPoint.y -= offset;
		//	endPoint.y += offset;
		//}
		////CRect rt(endPoint, startPoint);
		//CRect rt(startPoint, endPoint);
		CPoint invaldateStartPoint;
		CPoint invaldateEndPoint;
		//
		SetInvalidateArea(invaldateStartPoint, invaldateEndPoint);
		//


		CRect rt(invaldateStartPoint, invaldateEndPoint);
		InvalidateRect(rt, FALSE);
		//CRect rt(m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X - m_figure->startPoint.X, m_figure->endPoint.Y - m_figure->startPoint.Y);
		//InvalidateRect(rt, FALSE);
		//HBRUSH h_blue_brush = CreateSolidBrush(RGB(255, 255, 255));
		//HDC h_dc = ::GetDC(m_hWnd);
		//SelectObject(h_dc, h_blue_brush);
		//::ReleaseDC(m_hWnd, h_dc);
		//InvalidateRect(rt, FALSE);
		//CRect rt(m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X, m_figure->endPoint.Y);
		//CRect rt;
		//
		//CWnd *pWnd = AfxGetMainWnd();
		//HWND hWnd = pWnd->m_hWnd;
		//
		//::GetClientRect(hWnd, rt);
		//Invalidate(TRUE) 
		//InvalidateRect(TRUE);
		//InvalidateRect(rt,TRUE);
		//FillRect(h_dc,rt,h_blue_brush);
		//UpdateWindow() : 
		//UpdateWindow();
		//Invalidate(FALSE);
		//m_IsMouseMove = false;

	}
	CWnd::OnMouseMove(nFlags, point);
}

void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_IsMouseMove = false;
	m_IsBtnDown = false;
	SaveFigure(m_figure->startPoint,m_figure->endPoint);
	//if(m_figure == NULL)
	//	return;
	//m_point.X = point.x;
	//m_point.Y = point.y;
	//m_IsSetStart = false;
	//m_figure->SetPoint(m_point, m_IsSetStart);
	CWnd::OnLButtonUp(nFlags, point);
}

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	m_figureList = std::make_shared<CList<Figure, Figure&>>();

	return 0;
}

void CChildView::OnDrawCanvas() {
	if (m_canvas == nullptr)
		return;
	CPaintDC dc(this); // device context for painting

	Gdiplus::Graphics mainG(dc.GetSafeHdc());
	mainG.DrawImage(m_canvas.get(), 0, 0, m_canvas->GetWidth(), m_canvas->GetHeight());
}

void CChildView::InitCanvas() 
{
	CRect rect;
	this->GetClientRect(&rect);
	m_canvas = std::make_shared<Gdiplus::Bitmap>(rect.Width(), rect.Height());
	Gdiplus::Graphics graphicsOfcanvas(m_canvas.get());
	Gdiplus::SolidBrush whiteBrush(Gdiplus::Color(255, 255, 255, 255));
	graphicsOfcanvas.FillRectangle(&whiteBrush, 0, 0, rect.Width(), rect.Height());
}

void CChildView::SaveFigure(Gdiplus::Point startPoint, Gdiplus::Point endPoint) {

	Figure figure(startPoint, endPoint);
	m_figureList->AddTail(figure);
}

//void CChildView::LoadFigure(Gdiplus::Point &startPoint, Gdiplus::Point &endPoint) {
//	startPoint = m_figureList->GetTail().startPoint;
//	endPoint = m_figureList->GetTail().endPoint;
//}


void CChildView::OnSize(UINT nType, int cx, int cy)
{

	CWnd::OnSize(nType, cx, cy);

	if ((cx == 0) || (cy == 0))
	{
		return;
	}

	InitCanvas();
}
