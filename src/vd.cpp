/*
 * VD.CPP
 */

#include "vd.h"

int main()
{
    std::cout << "Starting VD.\n";

    // Initialising SDL.
    sdlc *container = NULL;
    try {
        container = initSDL();
    } catch (int err) {
        std::cerr << "Initialising failed: " << err << std::endl;
        return err;
    }

#ifdef DEBUG
    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN);
#endif

    start(container);

    // Cleaning up before exit.
    delete container;
    std::cout << "Bye bye!\n";
    return 0;
}

sdlc *initSDL()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        logCritical("SDL could not initialise!");
        throw 1;
    }

    SDL_DisplayMode *current = new SDL_DisplayMode;
    if(SDL_GetCurrentDisplayMode(0, current) != 0) {
        logCritical("SDL could not get display mode for video display!");
        throw 2;
    }

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    if(SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP, &window, &renderer) != 0) {
        logCritical("SDL could not initialise window and renderer!");
        throw 3;
    }

    SDL_Event *event = new SDL_Event;
    if(current != NULL && window != NULL && renderer != NULL && event != NULL) {
        return new sdlc(renderer, event, current, window);
    } else {
        logCritical("Something unexplained happened!");
        throw 4;
    }
}

void draw(SDL_Renderer *renderer, point_vec_t *points, ls_vec_t *linesegments, circle_vec_t *circles)
{
    SDL_RenderClear(renderer);
    for(pointit_vec_t p = points->begin(); p != points->end(); p++) {
        point_t *dp = (*p)->getPoint();
        SDL_RenderDrawPoint(renderer, dp->x, dp->y);
    }
    for(lsit_vec_t l = linesegments->begin(); l != linesegments->end(); l++) {
        point_vec_t *p = (*l)->getPoints();
        for(pointit_vec_t pit = p->begin(); pit != p->end(); pit++) {
            point_t *dp = (*pit)->getPoint();
            SDL_RenderDrawPoint(renderer, dp->x, dp->y);
        }
    }
    for(circleit_vec_t c = circles->begin(); c != circles->end(); c++) {
        point_vec_t *p = (*c)->getPoints();
        for(pointit_vec_t pit = p->begin(); pit != p->end(); pit++) {
            point_t *dp = (*pit)->getPoint();
            SDL_RenderDrawPoint(renderer, dp->x, dp->y);
        }
    }
}

void changeRadiusOnCircles(circle_vec_t *circles, const unsigned int size)
{
    for(circleit_vec_t pit = circles->begin(); pit != circles->end(); pit++) {
        unsigned int radius = (*pit)->getRadius();
        radius += size;
        (*pit)->changeRadius(radius);
    }
}

void logCritical(std::string err)
{
    err += std::string(" SDL ERROR: ") + std::string(SDL_GetError()) + std::string("\n");
    SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, err.c_str());
}

void render(SDL_Renderer *renderer)
{
    SDL_RenderPresent(renderer);
}

void rotate(point_vec_t *points, ls_vec_t *linesegments, const int degrees)
{
    for(pointit_vec_t p = points->begin(); p != points->end(); p++) {
        (*p)->rotate(degrees);
    }
    for(lsit_vec_t l = linesegments->begin(); l != linesegments->end(); l++) {
        (*l)->rotate(degrees);
    }
}

void start(sdlc *container)
{
    bool quit = false;
#ifdef DEBUG
    int xmax = container->current->w;
    int ymax = container->current->h;
#endif

    point_vec_t *points = new point_vec_t;
    ls_vec_t *linesegments = new ls_vec_t;
    circle_vec_t *circles = new circle_vec_t;

    points->push_back(new Point(new point_t(100,100)));
    points->push_back(new Point(new point_t(110,100)));
    points->push_back(new Point(new point_t(100,110)));
    points->push_back(new Point(new point_t(120,120)));
    points->push_back(new Point(new point_t(130,100)));
    points->push_back(new Point(new point_t(100,130)));
    points->push_back(new Point(new point_t(140,140)));

    for(int i = 200; i < 300; i++) {
        points->push_back(new Point(new point_t(i, i)));
    }

    for(int i = 350; i < 450; i++) {
        Point *p1 = new Point(new point_t(i, i));
        Point *p2 = new Point(new point_t(i+100, i+150));
        linesegments->push_back(new Linesegment(p1, p2));
    }

    Point *pcircle = new Point(new point_t(500, 350));
    circles->push_back(new Circle(pcircle, 30));

    while(!quit) {
        while(SDL_PollEvent(container->event) != 0) {
            if(container->event->key.keysym.scancode == SDL_SCANCODE_D) {
                draw(container->renderer, points, linesegments, circles);
                render(container->renderer);
            } else if(container->event->key.keysym.scancode == SDL_SCANCODE_C) {
                SDL_RenderClear(container->renderer);
                render(container->renderer);
            } else if(container->event->key.keysym.scancode == SDL_SCANCODE_R) {
                rotate(points, linesegments, -1);
                draw(container->renderer, points, linesegments, circles);
                render(container->renderer);
            } else if(container->event->key.keysym.scancode ==SDL_SCANCODE_T) {
                changeRadiusOnCircles(circles, 2);
                draw(container->renderer, points, linesegments, circles);
                render(container->renderer);
            } else if(container->event->key.keysym.scancode ==SDL_SCANCODE_Y) {
                changeRadiusOnCircles(circles, -2);
                draw(container->renderer, points, linesegments, circles);
                render(container->renderer);
            } else if(container->event->type == SDL_QUIT ||
                    container->event->key.keysym.scancode == SDL_SCANCODE_Q ||
                    container->event->key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                quit = true;
#ifdef DEBUG
            } else if(container->event->type == SDL_WINDOWEVENT && container->event->window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                xmax = container->current->w;
                ymax = container->current->h;
                std::cout << "XMAX: " << xmax << "\nYMAX: " << ymax << std::endl;
#endif
            }
        }
    }

    delete points;
    delete linesegments;
}
