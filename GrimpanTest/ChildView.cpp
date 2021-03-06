
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
	m_IsBtnDown = false;
	m_IsMouseMove = false;
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
	CBitmap bMap;
	
	CRect rt;
	GetClientRect(rt);
	bMap.CreateCompatibleBitmap(&dc, rt.right, rt.bottom);
	Gdiplus::SolidBrush mySolidBrush(Gdiplus::Color(255, 255, 255, 255));
	Gdiplus::Graphics mainG(dc.GetSafeHdc());
	Gdiplus::Graphics mainG();
	Gdiplus::RectF rect(0, 0, rt.Width(), rt.Height());
	mainG.FillRectangle(&mySolidBrush, rect);
	//memDC.CreateCompatibleDC(&dc);
	//Gdiplus::Graphics memG(memDC.GetSafeHdc());
	//mainG.DrawImage(m_canvas.get(), 0, 0, m_canvas->GetWidth(), m_canvas->GetHeight());
	
	//Gdiplus::Graphics g(m_canvas.get());
	//Gdiplus::Graphics g(hDC);
	Gdiplus::Pen pen(Gdiplus::Color(255, 255, 0, 0), 20);
	//return
	//??????
	
	Figure figure;
	POSITION pos = m_figureList->GetHeadPosition();
	for (int i = 1; i <= m_figureList->GetCount(); i++)
	{
		figure = m_figureList->GetNext(pos);
		mainG.DrawLine(&pen, figure.startPoint.X, figure.startPoint.Y, figure.endPoint.X, figure.endPoint.Y);
	}
	
	//if (m_IsMouseMove == true)
	//{
	//	Gdiplus::SolidBrush mySolidBrush(Gdiplus::Color(255, 255, 255, 255));
	//	Gdiplus::Rect rt(m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X - m_figure->startPoint.X, m_figure->endPoint.Y - m_figure->startPoint.Y);
	//	mainG.FillRectangle(&mySolidBrush,rt);
	//	HDC h_dc = ::GetDC(m_hWnd);
	//	BitBlt(h_dc, m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X - m_figure->startPoint.X, m_figure->endPoint.Y - m_figure->startPoint.Y, m_dc, 0, 0, SRCCOPY);

	//	::ReleaseDC(m_hWnd, h_dc);         // ???????? DC?? ????????.
	//	::ReleaseDC(m_hWnd, m_dc);  // ???????? DC?? ????????.

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
	switch (m_mode) //???? ????
	{
	case 1:
		break;
	case 2:
		mainG.DrawLine(&pen, m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X, m_figure->endPoint.Y);
		break;
	case 3:
		mainG.DrawRectangle(&pen, m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X - m_figure->startPoint.X, m_figure->endPoint.Y - m_figure->startPoint.Y);
		break;
	case 4:
		mainG.DrawEllipse(&pen, m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X, m_figure->endPoint.Y);
		break;
	case 5:
		Gdiplus::FontFamily fontFamily(L"Times New Roman");
		Gdiplus::Font font(&fontFamily, 24, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
		Gdiplus::PointF pointF(m_figure->endPoint.X, m_figure->endPoint.Y);
		Gdiplus::SolidBrush solidBrush(Gdiplus::Color(255, 0, 0, 255));

		mainG.DrawString(L"TEXT", -1, &font, pointF, &solidBrush);
		break;
	}
	//::ReleaseDC(hWnd, hDC);
}

void CChildView::OnDrawPot()
{
	m_mode = 1;
}


void CChildView::OnDrawLine()
{
	m_mode = 2;
}

void CChildView::OnDrawRect()
{
	m_mode = 3;
}

void CChildView::OnDrawEllipse()
{
	m_mode = 4;
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

	//
	//m_dc = ::GetDC(m_hWnd);
//	if (m_figureList->GetCount() != 0)
//	{
//		Invalidate(FALSE);
//	}
	
	//?????? ?????? ?????? ??
	m_IsBtnDown = true;
	
	//???? ???? ?? ?????? ?????? ?????? ???? ?????? ?????? ????.
	m_point.X = point.x;
	m_point.Y = point.y;

	// ?????? ???? ????.
	//m_figure = std::make_shared<Figure>();

	//?????? ??????.
	m_IsSetStart = true;
	m_figure->SetPoint(m_point, m_IsSetStart);

	//??????.
	//CPoint startPoint;
	//CPoint endPoint;
	/*
	int offset = 100;
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
	*/
	//CRect rt(startPoint, endPoint);
	//CRect rt(endPoint, startPoint);
	//InvalidateRect(rt, FALSE);
	//CRect rt(m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X - m_figure->startPoint.X, m_figure->endPoint.Y - m_figure->startPoint.Y);
	//InvalidateRect(rt,FALSE);
	//Invalidate(FALSE);
	CWnd::OnLButtonDown(nFlags, point);
}

void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	//???????? ????
	m_IsMouseMove = true;

	//CRect rt(m_figure->startPoint.X, m_figure->startPoint.Y, m_figure->endPoint.X - m_figure->startPoint.X, m_figure->endPoint.Y - m_figure->startPoint.Y);
	//InvalidateRect(rt, FALSE);

	//?????? ?????? ??????
	if (m_IsBtnDown == true) {
		//UpdateWindow();
		//if (m_figureList->GetCount() != 0)
		//{
			
			//Invalidate(FALSE);
		//}
		if (m_figure == NULL)
			return;

		//?????? ?????? ???? ???? ?????? ????
		m_point.X = point.x;
		m_point.Y = point.y;

		//?????? ???????? false?? ??????
		m_IsSetStart = false;
		
		//?????? ?????? ?????? ???????? ????
		m_figure->SetPoint(m_point, m_IsSetStart);

		//CPoint ???? ????
		CPoint startPoint;
		CPoint endPoint;

		//InvalidateRect ?? ???? ????
		int offset = 50;

		//GDIplus::Point?? CPoint?? ????
		startPoint.x = m_figure->startPoint.X;
		startPoint.y = m_figure->startPoint.Y;
		endPoint.x = m_figure->endPoint.X;
		endPoint.y = m_figure->endPoint.Y;

		//???? ???? ???? ???? ???? ???? ???????? offset ?? ????
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

		//?????? ?????? rect?? ????
		CRect rt(startPoint, endPoint);
		//TRUE -> InvalidateRect?? ?????? ?????? ???? ?????? , FALSE -> WM_PAINT?? ?????? ?? ?????? ?????????? ????.
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
		//?????? ???? ????
		//CWnd *pWnd = AfxGetMainWnd();
		//HWND hWnd = pWnd->m_hWnd;
		//?????? ???? ??????
		//::GetClientRect(hWnd, rt);
		//Invalidate(TRUE) : WM_PAINT ?????? ????, TRUE:???? ???? ?????? / FALSE:???? ???? ??????
		//InvalidateRect(TRUE);
		//InvalidateRect(rt,TRUE);
		//FillRect(h_dc,rt,h_blue_brush);
		//UpdateWindow() : ?????? ?????? ?????? ???? ??????????
		//UpdateWindow();
		//Invalidate(FALSE);

	}
	CWnd::OnMouseMove(nFlags, point);
}

void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	//?????? ???? ????
	m_IsMouseMove = false;

	//???? ???? ????
	m_IsBtnDown = false;

	SaveFigure(m_figure->startPoint,m_figure->endPoint);
	//if(m_figure == NULL)
	//return;
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
	// ?????? ???? ????.
	m_figure = std::make_shared<Figure>();
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

void CChildView::LoadFigure(Gdiplus::Point &startPoint, Gdiplus::Point &endPoint) {
	startPoint = m_figureList->GetTail().startPoint;
	endPoint = m_figureList->GetTail().endPoint;
}


void CChildView::OnSize(UINT nType, int cx, int cy)
{

	CWnd::OnSize(nType, cx, cy);

	if ((cx == 0) || (cy == 0))
	{
		return;
	}

	InitCanvas();
}
