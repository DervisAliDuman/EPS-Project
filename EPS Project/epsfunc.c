//1801042626 Derviş Ali Duman
#include <stdio.h>	
#include<stdlib.h>
#include<math.h>
#include "epslib.h"

Figure *start_figure(double width, double height){
	//occuring new figure and returning
	Figure *fig=(Figure *)malloc(sizeof(Figure));
	fig->width=width;
	fig->height=height;
	fig->next=NULL;
	return fig;
}

void set_thickness_resolution(Figure *fig, double thickness, double resolution){
	//implementig thickness and resolution of figure
	fig->thickness=thickness;
	fig->resolution=resolution;
}

void set_color(Figure * fig,Color c){
	//implementig color of figure
	fig->color.red=c.red;
	fig->color.green=c.green;
	fig->color.blue=c.blue;
}

void point_inserter(Point2D *head, double x, double y){
	//inserts point to last of point2D struct
	Point2D *iter,*will_add=(Point2D*)malloc(sizeof(Point2D));
	will_add->x=x;
 	will_add->y=y;
 	will_add->next=NULL; 	//last point is done
	
	iter = head; 

 	while(iter->next!= NULL){
 		iter=iter->next; 
 	}
 
 	iter->next=will_add;	
}

void draw_fx(Figure * fig, double f(double x),double start_x, double end_x,double step_size){
	//draws given f(x) function
	
	Point2D *head= (Point2D*)malloc(sizeof(Point2D)),*iter= (Point2D*)malloc(sizeof(Point2D));
	double i;
	iter=head;

	iter->x=start_x;
	iter->y=f(start_x);
	
	for (i = start_x + step_size; i <= end_x ; i += step_size){
		point_inserter(iter, i, f(i));
	 	iter=iter->next;
	}
                      
	fig->pointt=head; 
}



void draw_polyline(Figure *fig, Point2D * poly_line, int n){
	//draws poly line that user implemented on poly line struct

	Point2D * iter=poly_line;
	fig->pointt=poly_line;

	while(iter->next!= NULL){
		iter=iter->next;
	}
	iter->next= (Point2D*)malloc(sizeof(Point2D));
	iter->next->x=0;
	iter->next->y=0;
	iter=iter->next;
	iter->next=NULL;
}

void draw_ellipse(Figure* fig,Point2D * center,Point2D * width_height){
	//draws ellipse by using coordinates 

	double center_x=center->x /2; 		
	double center_y=center->y /2;
	double a=width_height->x/2,b=width_height->y/2;
	double i;

	Point2D *head = (Point2D*)malloc(sizeof(Point2D));
	Point2D *iter = head;

	for(i=0 ; i<=360 ; i+=(1/fig->resolution)){	
		//It doesn't like classic formula of ellipse, here I tried to find positions.
		iter->x=center_x+cos(i* M_PI / 180.0)*a; 
		iter->y=center_y+sin(i* M_PI / 180.0)*b;
		iter->next=(Point2D*)malloc(sizeof(Point2D));
		iter=iter->next;
		iter->next=NULL;
	}

	fig->pointt=head;
}

void draw_polygon(Figure* fig,Point2D * poly_line){
	//draws polygon like I did while draw polyline structure
	Point2D * iter=poly_line;
	fig->pointt=poly_line;

	double start_x=iter->x;
	double start_y=iter->y;

	while(iter->next!= NULL){
		iter=iter->next;
	}
	iter->next= (Point2D*)malloc(sizeof(Point2D));
	iter->next->x=start_x;
	iter->next->y=start_y;
	iter=iter->next;
	iter->next=NULL;

	iter->next= (Point2D*)malloc(sizeof(Point2D));
	iter->next->x=start_x;
	iter->next->y=start_y;
	iter=iter->next;
	iter->next=NULL;
}

void append_figures(Figure *fig1, Figure *fig2){
	//appends fig2 to last member of fig1 
	while(fig1->next!=NULL){
		fig1=fig1->next;
	}
	fig1->next=(Figure *)malloc(sizeof(Figure));
	fig1->next=fig2;
}

void draw_tree_line(Figure * fig,double start_x, double end_x,double step_size){
	Point2D *head= (Point2D*)malloc(sizeof(Point2D)),*iter= (Point2D*)malloc(sizeof(Point2D));
	double i;
	iter=head;

	iter->x=start_x;
	iter->y=-start_x;
	
	for (i = start_x + step_size; i <= end_x ; i += step_size){
		point_inserter(iter, i, -i);
	 	iter=iter->next;
	}
                      
	fig->pointt=head; 
}

void draw_tree_circle(Figure* fig,Point2D * center){

	double center_x=center->x /2; 		
	double center_y=center->y /2;
	double a=5,b=5,i;

	Point2D *head = (Point2D*)malloc(sizeof(Point2D));
	Point2D *iter = head;

	for(i=0 ; i<=360 ; i+=(1/fig->resolution)){
		iter->x=center_x+cos(i* M_PI / 180.0)*a; 
		iter->y=center_y+sin(i* M_PI / 180.0)*b;
		iter->next=(Point2D*)malloc(sizeof(Point2D));
		iter=iter->next;
		iter->next=NULL;
	}

	fig->pointt=head;
}

void draw_binary_tree(Figure* fig, Tree * root, Point2D *center){
	//I think It is very close to solution but It gives me segmentation fault 
	Color c;
	static int a;
	if (a==0){
	 	draw_tree_circle(fig,center);
	 	a=99;
	} 
	c.red=1;c.green=0;c.blue=1;

	Figure *circle1,*circle2,*line1,*line2;

	circle1= start_figure(250.0, 250.0);
	set_thickness_resolution(circle1, 0.2, 10);
    set_color(circle1, c);

	circle2= start_figure(250.0, 250.0);
	set_thickness_resolution(circle2, 0.2, 10);
    set_color(circle2, c);

	line1= start_figure(250.0, 250.0);
	set_thickness_resolution(line1, 0.2, 10);
    set_color(line1, c);

	line2= start_figure(250.0, 250.0);
	set_thickness_resolution(line2, 0.2, 10);
    set_color(line2, c);

	if (root!=NULL){
		if (root->right!=NULL){
			draw_tree_line(line1,center->x,center->x+5,1/line1->resolution);
			center->x+=15;
			center->x-=15;
			draw_tree_circle(circle1,center);
			append_figures(fig,circle1);
			append_figures(fig,line1);
			draw_binary_tree(fig,root->right,center);
		}

		if (root->left != NULL){
			draw_tree_line(line2,center->x,center->x-5,1/line2->resolution);
			center->x-=15;
			center->x-=15;
			draw_tree_circle(circle2,center);
			append_figures(fig,circle2);
			append_figures(fig,line2);
			draw_binary_tree(fig,root->left,center);
		}
	}
}

void scale_figure(Figure *fig, double scale_x, double scale_y){
	//scales the figure
	Point2D *iter=fig->pointt;
	while(iter!= NULL){
		iter->x *=scale_x;
		iter->y *=scale_y;
		iter=iter->next;
	}
}

void resize_figure(Figure *fig,Point2D *start_roi, Point2D *end_roi){
	//resizing and because of resizing some points should ignore while drawing.
	Point2D *iter=fig->pointt;
	//fig->width=end_roi->x - start_roi->x;
	//fig->height=end_roi->y - start_roi->y;
	while(iter!= NULL){
		if (end_roi->x < iter->x || end_roi->y < iter->y || start_roi->x > iter->x || start_roi->y > iter->y){
			iter->ignore=1;
		}
		iter=iter->next;
	}
}

void export_eps(Figure * fig, char * file_name){
	//exporting figures and next figures like linked list (linked figure)
	Point2D *iter; 

	FILE *fp=fopen(file_name,"w");
	
	fprintf(fp,"!PS-Adobe-3.0 EPSF-3.0\n");
	fprintf(fp,"%%%%BoundingBox: %lf %lf %lf %lf\n",0.0,0.0,fig->width,fig->height);
	
	//Before that I really didn't want to deal with making bounding box; So,like there is bounding box, here I used width/2 and height/2
	while(fig != NULL){
		iter=fig->pointt;
		fprintf(fp,"%lf setlinewidth\n",fig->thickness);
		fprintf(fp,"%lf %lf %lf setrgbcolor\n",fig->color.red,fig->color.green,fig->color.blue);
		fprintf(fp,"%lf %lf moveto\n",iter->x + fig->width/2.0 , iter->y + fig->height/2.0);
		
		iter=iter->next;

		while(iter->next != NULL){
			if (iter->ignore != 1){
				fprintf(fp,"%lf %lf lineto\n",iter->x + fig->width/2.0,iter->y + fig->height/2.0);
			}
			else{
				fprintf(fp,"%lf %lf moveto\n",iter->x + fig->width/2.0 , iter->y + fig->height/2.0);
			}
			
			iter=iter->next;
		}
		fig=fig->next;
		fprintf(fp,"stroke\n"); 	
	}
	
	fclose(fp);
}