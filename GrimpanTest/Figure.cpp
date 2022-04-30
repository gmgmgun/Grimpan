#include "pch.h"
#include "Figure.h"

#define SIZE 10

void Figure::SetPoint(Gdiplus::Point point, int m_IsSetStart)
{
	if(m_IsSetStart == true)
	{
		startPoint.X = point.X;
		startPoint.Y = point.Y;
		endPoint.X = point.X;
		endPoint.Y = point.Y;
	}
	else if (m_IsSetStart == false)
	{
		endPoint.X = point.X;
		endPoint.Y = point.Y;
	}

}

void Figure::Pot(Gdiplus::Graphics * g, Gdiplus::Point * point)
{
	
}

void Figure::Line()
{

}
void Figure::Rect(Gdiplus::Graphics * g, Gdiplus::Point * point)
{
	
}
void Figure::Ellipse(Gdiplus::Graphics * g, Gdiplus::Point * point)
{
	
}

void Figure::Text(Gdiplus::Graphics * g, Gdiplus::Point * point)
{
		 
}

void Figure::Clear()
{

}