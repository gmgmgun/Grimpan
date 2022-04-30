#pragma once
#include <memory>
	class Figure
	{
	public:
		Gdiplus::Point startPoint;
		Gdiplus::Point endPoint;
		Figure()
		{

			startPoint.X = 0;
			startPoint.Y = 0;
			endPoint.X = 0;
			endPoint.Y = 0;

		}
		Figure(Gdiplus::Point startPoint, Gdiplus::Point endPoint)
		{

			this->startPoint = startPoint;

			this->endPoint = endPoint;
				
		}
		std::shared_ptr<Gdiplus::Bitmap> m_canvas;
		void Pot(Gdiplus::Graphics * g, Gdiplus::Point * point);
		void Line();
		void Rect(Gdiplus::Graphics * g, Gdiplus::Point * point);
		void Ellipse(Gdiplus::Graphics * g, Gdiplus::Point * point);
		void Text(Gdiplus::Graphics * g, Gdiplus::Point * point);
		void Clear();
		void SetPoint(Gdiplus::Point point, int IsBtnDown);
	
		
	};