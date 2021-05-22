//1801042626 Derviş Ali Duman
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include "epslib.h"

double fx_graph(double x){	//F(x) graph function
	return pow(x,2)/500.0 -50;
}

int main(){
	Color c;

	//tree implemention
	Tree* root; 
	root=(Tree*)malloc(sizeof(Tree));
	root->data=10;
	root->right=NULL;
	root->left=NULL;
	root->right=(Tree*)malloc(sizeof(Tree));
	root->right->data=89;
	root->right->right=NULL;
	root->right->left=NULL;
	root->left=(Tree*)malloc(sizeof(Tree));
	root->left->data=100;
	root->left->right=NULL;
	root->left->left=NULL;
	root->right->right=(Tree*)malloc(sizeof(Tree));
	root->right->right->data=54;
	root->right->right->right=NULL;
	root->right->right->left=NULL;
	root->left->left=(Tree*)malloc(sizeof(Tree));
	root->left->left->data=4;
	root->left->left->right=NULL;
	root->left->left->left=NULL;
	root->left->right=(Tree*)malloc(sizeof(Tree));
	root->left->right->data=11;
	root->left->right->right=NULL;
	root->left->right->left=NULL;
	//tree implemention is done

	//draw fx
	c.red=0;c.green=2;c.blue=30;
	Figure *figure1;
	
	figure1= start_figure(250.0, 250.0);
	set_thickness_resolution(figure1, 0.2, 10);
    set_color(figure1, c);
	draw_fx(figure1, fx_graph, -75, 75, 1.0/figure1->resolution);
	export_eps(figure1,"fx.eps");
	//end of draw fx

	//draw ellipse
	Point2D * width_height=(Point2D*)malloc(sizeof(Point2D));
	width_height->next=NULL;
	width_height->x=150;	//write your width value
	width_height->y=100;	//write your height value

	Point2D * center=(Point2D*)malloc(sizeof(Point2D));
					//implementing center point
	center->x=100;
	center->y=100;

	c.red=1;c.green=2;c.blue=0;
	Figure *figure3;

	figure3= start_figure(250.0, 250.0);
	set_thickness_resolution(figure3, 2, 10);
    set_color(figure3, c);
	draw_ellipse(figure3,center,width_height);
	export_eps(figure3,"ellipse.eps");
	//end of ellipse

	//draw polyline
				//implementing polyline points
	Point2D * poly_line=(Point2D*)malloc(sizeof(Point2D));
	poly_line->x=-50;	
	poly_line->y=50;
	poly_line->next=(Point2D*)malloc(sizeof(Point2D));
	poly_line->next->x=0;
	poly_line->next->y=50;
	poly_line->next->next=(Point2D*)malloc(sizeof(Point2D));
	poly_line->next->next->x=0;
	poly_line->next->next->y=100;
	poly_line->next->next->next=NULL;
	poly_line->next->next->next=(Point2D*)malloc(sizeof(Point2D));
	poly_line->next->next->next->x=-50;
	poly_line->next->next->next->y=100;
	poly_line->next->next->next->next=NULL;
				//implementing polyline points done
	c.red=1;c.green=0;c.blue=0;
	Figure *figure6;

	figure6= start_figure(250.0, 250.0);

	set_thickness_resolution(figure6, 0.9, 10);
    set_color(figure6, c);
	draw_polyline(figure6,poly_line,0);
	export_eps(figure6,"polyline.eps");
	//end of polyline
	
	//polygon
					//implementing polygone points
	Point2D * poly_line2=(Point2D*)malloc(sizeof(Point2D));
	poly_line2->x=50;	
	poly_line2->y=50;
	poly_line2->next=(Point2D*)malloc(sizeof(Point2D));
	poly_line2->next->x=100;
	poly_line2->next->y=50;
	poly_line2->next->next=(Point2D*)malloc(sizeof(Point2D));
	poly_line2->next->next->x=100;
	poly_line2->next->next->y=100;
	poly_line2->next->next->next=NULL;
	poly_line2->next->next->next=(Point2D*)malloc(sizeof(Point2D));
	poly_line2->next->next->next->x=50;
	poly_line2->next->next->next->y=100;
	poly_line2->next->next->next->next=NULL;
					//implementing polygone points
	c.red=1;c.green=0;c.blue=1;
	Figure *figure5;

	figure5= start_figure(250.0, 250.0);

	set_thickness_resolution(figure5, 0.2, 10);
    set_color(figure5, c);
	draw_polygon(figure5,poly_line2);
	export_eps(figure5,"polygon.eps");
	//end of polygon

	/*
	//tree				////UNEXPECTEDLY SEGMENTATİON FAULT 
	c.red=1;c.green=0;c.blue=1;
	Figure *figure4= start_figure(250.0, 250.0);
	set_thickness_resolution(figure5, 0.2, 10);
    set_color(figure5, c);
    draw_binary_tree(figure5,root,center);
	export_eps(figure4,"tree.eps");
	//end tree
	*/
	scale_figure(figure3,0.2, 0.2);	//I scaled my ellipse 

	//Resizing statement
	Point2D *start_roi=(Point2D*)malloc(sizeof(Point2D));
	Point2D *end_roi=(Point2D*)malloc(sizeof(Point2D));
	start_roi->x=0;
	start_roi->y=0;
	end_roi->x=20;
	end_roi->y=20;
	resize_figure(figure3, start_roi, end_roi);	//I resized my ellipse
	//end of resizing
	
	append_figures(figure1,figure3);
	append_figures(figure1,figure5);
	append_figures(figure1,figure6);
	export_eps(figure1,"appended.eps");

	return 0;
}