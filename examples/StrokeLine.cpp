/*
 * Copyright (c) 2020 - 2024 the ThorVG project. All rights reserved.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "Example.h"

/************************************************************************/
/* ThorVG Drawing Contents                                              */
/************************************************************************/

struct UserExample : tvgexam::Example
{
    bool content(tvg::Canvas* canvas, uint32_t w, uint32_t h) override
    {
        if (!canvas) return false;

        //Test for StrokeJoin & StrokeCap
        auto shape1 = tvg::Shape::gen();
        shape1->moveTo( 20, 50);
        shape1->lineTo(250, 50);
        shape1->lineTo(220, 200);
        shape1->lineTo( 70, 170);
        shape1->lineTo( 70, 30);
        shape1->strokeFill(255, 0, 0);
        shape1->strokeWidth(10);
        shape1->strokeJoin(tvg::StrokeJoin::Round);
        shape1->strokeCap(tvg::StrokeCap::Round);
        canvas->push(std::move(shape1));

        auto shape2 = tvg::Shape::gen();
        shape2->moveTo(270, 50);
        shape2->lineTo(500, 50);
        shape2->lineTo(470, 200);
        shape2->lineTo(320, 170);
        shape2->lineTo(320, 30);
        shape2->strokeFill(255, 255, 0);
        shape2->strokeWidth(10);
        shape2->strokeJoin(tvg::StrokeJoin::Bevel);
        shape2->strokeCap(tvg::StrokeCap::Square);
        canvas->push(std::move(shape2));

        auto shape3 = tvg::Shape::gen();
        shape3->moveTo(520, 50);
        shape3->lineTo(750, 50);
        shape3->lineTo(720, 200);
        shape3->lineTo(570, 170);
        shape3->lineTo(570, 30);
        shape3->strokeFill(0, 255, 0);
        shape3->strokeWidth(10);
        shape3->strokeJoin(tvg::StrokeJoin::Miter);
        shape3->strokeCap(tvg::StrokeCap::Butt);
        canvas->push(std::move(shape3));

        //Test for Stroke Dash
        auto shape4 = tvg::Shape::gen();
        shape4->moveTo( 20, 230);
        shape4->lineTo(250, 230);
        shape4->lineTo(220, 380);
        shape4->lineTo( 70, 330);
        shape4->lineTo( 70, 210);
        shape4->strokeFill(255, 0, 0);
        shape4->strokeWidth(5);
        shape4->strokeJoin(tvg::StrokeJoin::Round);
        shape4->strokeCap(tvg::StrokeCap::Round);

        float dashPattern1[2] = {20, 10};
        shape4->strokeDash(dashPattern1, 2);
        canvas->push(std::move(shape4));

        auto shape5 = tvg::Shape::gen();
        shape5->moveTo(270, 230);
        shape5->lineTo(500, 230);
        shape5->lineTo(470, 380);
        shape5->lineTo(320, 330);
        shape5->lineTo(320, 210);
        shape5->strokeFill(255, 255, 0);
        shape5->strokeWidth(5);
        shape5->strokeJoin(tvg::StrokeJoin::Bevel);
        shape5->strokeCap(tvg::StrokeCap::Square);

        float dashPattern2[2] = {10, 10};
        shape5->strokeDash(dashPattern2, 2);
        canvas->push(std::move(shape5));

        auto shape6 = tvg::Shape::gen();
        shape6->moveTo(520, 230);
        shape6->lineTo(750, 230);
        shape6->lineTo(720, 380);
        shape6->lineTo(570, 330);
        shape6->lineTo(570, 210);
        shape6->strokeFill(0, 255, 0);
        shape6->strokeWidth(5);
        shape6->strokeJoin(tvg::StrokeJoin::Miter);
        shape6->strokeCap(tvg::StrokeCap::Butt);

        float dashPattern3[6] = {10, 10, 1, 8, 1, 10};
        shape6->strokeDash(dashPattern3, 6);
        canvas->push(std::move(shape6));

        //For a comparison with shapes 10-12
        auto shape7 = tvg::Shape::gen();
        shape7->appendArc(70, 400, 160, 10, 70, true);
        shape7->strokeFill(255, 0, 0);
        shape7->strokeWidth(7);
        shape7->strokeJoin(tvg::StrokeJoin::Round);
        shape7->strokeCap(tvg::StrokeCap::Round);
        canvas->push(std::move(shape7));

        auto shape8 = tvg::Shape::gen();
        shape8->appendArc(320, 400, 160, 10, 70, false);
        shape8->strokeFill(255, 255, 0);
        shape8->strokeWidth(7);
        shape8->strokeJoin(tvg::StrokeJoin::Bevel);
        shape8->strokeCap(tvg::StrokeCap::Square);
        canvas->push(std::move(shape8));

        auto shape9 = tvg::Shape::gen();
        shape9->appendArc(570, 400, 160, 10, 70, true);
        shape9->strokeFill(0, 255, 0);
        shape9->strokeWidth(7);
        shape9->strokeJoin(tvg::StrokeJoin::Miter);
        shape9->strokeCap(tvg::StrokeCap::Butt);
        canvas->push(std::move(shape9));

        //Test for Stroke Dash for Arc, Circle, Rect
        auto shape10 = tvg::Shape::gen();
        shape10->appendArc(70, 600, 160, 10, 30, true);
        shape10->appendCircle(70, 700, 20, 60);
        shape10->appendRect(130, 710, 100, 40);
        shape10->strokeFill(255, 0, 0);
        shape10->strokeWidth(5);
        shape10->strokeJoin(tvg::StrokeJoin::Round);
        shape10->strokeCap(tvg::StrokeCap::Round);
        shape10->strokeDash(dashPattern1, 2);
        canvas->push(std::move(shape10));

        auto shape11 = tvg::Shape::gen();
        shape11->appendArc(320, 600, 160, 10, 30, false);
        shape11->appendCircle(320, 700, 20, 60);
        shape11->appendRect(380, 710, 100, 40);
        shape11->strokeFill(255, 255, 0);
        shape11->strokeWidth(5);
        shape11->strokeJoin(tvg::StrokeJoin::Bevel);
        shape11->strokeCap(tvg::StrokeCap::Square);
        shape11->strokeDash(dashPattern2, 2);
        canvas->push(std::move(shape11));

        auto shape12 = tvg::Shape::gen();
        shape12->appendArc(570, 600, 160, 10, 30, true);
        shape12->appendCircle(570, 700, 20, 60);
        shape12->appendRect(630, 710, 100, 40);
        shape12->strokeFill(0, 255, 0);
        shape12->strokeWidth(5);
        shape12->strokeJoin(tvg::StrokeJoin::Miter);
        shape12->strokeCap(tvg::StrokeCap::Butt);
        shape12->strokeDash(dashPattern3, 6);
        canvas->push(std::move(shape12));

        return true;
    }
};


/************************************************************************/
/* Entry Point                                                          */
/************************************************************************/

int main(int argc, char **argv)
{
    return tvgexam::main(new UserExample, argc, argv);
}