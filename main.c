#include "Resource.h"
#include "DGL.h"
#include "graphics.h"
#include <stdlib.h>
#include <stdio.h>//for printf
#include <math.h>

float Dist2D(float x1, float y1, float x2, float y2) {
    return roundf(sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
    //return fabsf(x1 - x2) + fabsf(y1 - y2);
}
//float LightDist(unsigned char x1, unsigned char x2, unsigned char )

DGL_Mesh* CreateMesh(float width, float height, int dir, float cols, float rows) {
    DGL_Graphics_StartMesh();
    DGL_Color color = { 1.0f, 1.0f, 1.0f, 0.0f };
    float uWidth = 1.0f / cols;
    float vHeight = 1.0f / rows;

    if (dir == 0) {//center
        //bottom left, top left, top right, bottom right
        DGL_Vec2 pos = { -width/2.0f, -height/2.0f };
        DGL_Vec2 uv = { 0.0f, vHeight };
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ -width/2.0f, height/2.0f};
        uv = (DGL_Vec2){ 0.0f, 0.0f };
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ width/2.0f, height/2.0f 
        };

        uv = (DGL_Vec2){ uWidth, 0.0f };
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ -width/2.0f, -height/2.0f };
        uv = (DGL_Vec2){ 0.0f, vHeight};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ width/2.0f, height/2.0f };
        uv = (DGL_Vec2){ uWidth, 0.0f };
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ width/2.0f, -height/2.0f};
        uv = (DGL_Vec2){ uWidth, vHeight };
        DGL_Graphics_AddVertex(&pos, &color, &uv);
    }
    if (dir == 1) {//left NOT USED IN PRACTICE, JUST INVERT RIGHT
        //bottom left, top left, top right,     second bottom left, top right bottom right
        DGL_Vec2 pos = { -width, -height };
        DGL_Vec2 uv = {0.0f, vHeight};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ -width, height };
        uv = (DGL_Vec2){ 0.0f, 0.0f };
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ 0.0f,  height };
        uv = (DGL_Vec2){uWidth, 0.0f};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        //second triangle
        pos = (DGL_Vec2){ -width, -height };
        uv = (DGL_Vec2){0.0f, vHeight};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ 0.0f, height };
        uv = (DGL_Vec2){uWidth, 0.0f};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ 0.0f, -height };
        uv = (DGL_Vec2){uWidth, vHeight};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
    }

    if (dir == 2) {//right
        //bottom left, top left, top right,     second bottom left, top right bottom right
        DGL_Vec2 pos = {  width, -height };
        DGL_Vec2 uv = {uWidth, vHeight};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ width, height };
        uv = (DGL_Vec2){ uWidth, 0.0f };
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ 0.0f,  height };
        uv = (DGL_Vec2){0.0f, 0.0f};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        //second triangle
        pos = (DGL_Vec2){ width, -height };
        uv = (DGL_Vec2){uWidth, vHeight};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ 0.0f, height };
        uv = (DGL_Vec2){0.0f, 0.0f};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ 0.0f, -height };
        uv = (DGL_Vec2){0.0f, vHeight};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
    }
    if (dir == 3) {//bottom
        //bottom left, top left, top right,        second bottom left, top right bottom right
        DGL_Vec2 pos = { -width / 2.0f, 0.0f};
        DGL_Vec2 uv = {0.0f, vHeight};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ -width / 2.0f, height};
        uv = (DGL_Vec2){ 0.0f, 0.0f };
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ width / 2.0f, height };
        uv = (DGL_Vec2){uWidth, 0.0f};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        //second
        pos = (DGL_Vec2){ -width / 2.0f, 0.0f};
        uv = (DGL_Vec2){0.0f, vHeight};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ width / 2.0f, height };
        uv = (DGL_Vec2){uWidth, 0.0f};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ width / 2.0f, 0.0f };
        uv = (DGL_Vec2){uWidth, vHeight};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
    }
    if (dir == 4) {//top (seem on top)
        //bottom left, top left, top right,       second bottom left, top right bottom right
        DGL_Vec2 pos = { -width / 2.0f, -height};
        DGL_Vec2 uv = {0.0f, vHeight};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ -width / 2.0f, 0.0f};
        uv = (DGL_Vec2){ 0.0f, 0.0f };
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ width / 2.0f, 0.0f };
        uv = (DGL_Vec2){uWidth, 0.0f};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        //second
        pos = (DGL_Vec2){ -width / 2.0f, -height};
        uv = (DGL_Vec2){0.0f, vHeight};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ width / 2.0f, 0.0f};
        uv = (DGL_Vec2){uWidth, 0.0f};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
        pos = (DGL_Vec2){ width / 2.0f, -height};
        uv = (DGL_Vec2){uWidth, vHeight};
        DGL_Graphics_AddVertex(&pos, &color, &uv);
    }
    return DGL_Graphics_EndMesh();
};
DGL_Mesh* CreateMeshSheet(float width, float height, float columns, float rows)
{
    float halfWidth = width / 2.0f;
    float halfHeight = height / 2.0f;

    // Adjust the texture coordinates based on the animation frames
    float uWidth = 1.0f / columns;
    float vHeight = 1.0f / rows;

    DGL_Graphics_StartMesh();

    DGL_Vec2 pos = { -halfWidth, -halfHeight };
    DGL_Color color = { 1.0f, 1.0f, 1.0f, 0.0f };
    DGL_Vec2 uv = { 0.0f, vHeight };                // Bottom left coordinate
    DGL_Graphics_AddVertex(&pos, &color, &uv);

    pos = (DGL_Vec2){ -halfWidth, halfHeight };
    uv = (DGL_Vec2){ 0.0f, 0.0f };                  // Top left coordinate
    DGL_Graphics_AddVertex(&pos, &color, &uv);

    pos = (DGL_Vec2){ halfWidth, halfHeight };
    uv = (DGL_Vec2){ uWidth, 0.0f };                // Top right coordinate
    DGL_Graphics_AddVertex(&pos, &color, &uv);

    pos = (DGL_Vec2){ -halfWidth, -halfHeight };
    uv = (DGL_Vec2){ 0.0f, vHeight };               // Bottom left coordinate
    DGL_Graphics_AddVertex(&pos, &color, &uv);

    pos = (DGL_Vec2){ halfWidth, halfHeight };
    uv = (DGL_Vec2){ uWidth, 0.0f };                // Top right coordinate
    DGL_Graphics_AddVertex(&pos, &color, &uv);

    pos = (DGL_Vec2){ halfWidth, -halfHeight };
    uv = (DGL_Vec2){ uWidth, vHeight };             // Bottom right coordinate
    DGL_Graphics_AddVertex(&pos, &color, &uv);

    return DGL_Graphics_EndMesh();
}






//Definitions
DGL_Vec2 scale;// = { 64.0, 64.0 };

DGL_Mesh* tempmesh;// = CreateMesh(1.0f, 1.0f, 0, 1, 1);

DGL_Mesh* mesh;// = CreateMesh(scale.x, scale.y, 0, 3, 3);
DGL_Mesh* meshleft;// = CreateMesh(scale.x, scale.y, 1, 3, 3);
DGL_Mesh* meshright;// = CreateMesh(scale.x, scale.y, 2, 3, 3);
DGL_Mesh* meshtop;// = CreateMesh(scale.x, scale.y, 3, 3, 3);
DGL_Mesh* meshbot;// = CreateMesh(scale.x, scale.y, 4, 3, 3);


//.\Assets\Textures\00\00.png
TextureList* textureList;//; = loadTextures(0, 10);
TextureList* backgroundList;//; = loadTextures(0, 10);




//exit the window, cleanup;
void exitWindow() {
    freeTextures(textureList);
    DGL_Graphics_FreeMesh(&mesh);// = CreateMesh(scale.x, scale.y, 0, 3, 3);
    DGL_Graphics_FreeMesh(&meshleft);// = CreateMesh(scale.x, scale.y, 0, 3, 3);
    DGL_Graphics_FreeMesh(&meshright);// = CreateMesh(scale.x, scale.y, 0, 3, 3);
    DGL_Graphics_FreeMesh(&meshtop);// = CreateMesh(scale.x, scale.y, 0, 3, 3);
    DGL_Graphics_FreeMesh(&meshbot);// = CreateMesh(scale.x, scale.y, 0, 3, 3);
    
}



LRESULT CALLBACK WndProc(_In_ HWND hWnd, _In_ UINT message, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
    int result;
    if (DGL_System_HandleWindowsMessage(message, wParam, lParam, &result))
        return result;
    switch (message)
    {
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
}
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    lpCmdLine;
    hPrevInstance;
    DGL_SysInitInfo initInfo;
    initInfo.mAppInstance = hInstance;
    initInfo.mClassStyle = CS_HREDRAW | CS_VREDRAW;
    initInfo.mMaxFrameRate = 60;
    initInfo.mShow = nCmdShow;
    initInfo.mWindowStyle = WS_EX_TOPMOST | WS_POPUP;//WS_OVERLAPPEDWINDOW;
    initInfo.mWindowTitle = "...?";
    initInfo.mWindowWidth = 1920;
    initInfo.mWindowHeight = 1080;
    //initInfo.mWindowWidth = 640;
    //initInfo.mWindowHeight = 640;
    initInfo.mCreateConsole = TRUE;
    initInfo.pWindowsCallback = WndProc;
    initInfo.mWindowIcon = IDI_DGLTEMPLATE;
    DGL_Input_ShowCursor(FALSE);
    HWND windowHandle = DGL_System_Init(&initInfo);
    if (windowHandle == NULL)
        return 1;
    DGL_Color color = { 0.1f, 0.1f, 0.1f, 1.0f };
    DGL_Graphics_SetBackgroundColor(&color);
    //DGL_Mesh* mesh = CreateMesh(128, 128, 8, 8);
    
    scale = (DGL_Vec2){ 16.0, 16.0 };

    tempmesh = CreateMesh(1.0f, 1.0f, 0, 1, 1);
    mesh = CreateMesh(scale.x, scale.y, 0, 3, 3);
    meshleft = CreateMesh(scale.x, scale.y, 1, 3, 3);
    meshright = CreateMesh(scale.x, scale.y, 2, 3, 3);
    meshtop = CreateMesh(scale.x, scale.y, 3, 3, 3);
    meshbot = CreateMesh(scale.x, scale.y, 4, 3, 3);


    //.\Assets\Textures\00\00.png
    textureList = loadTextures(2, 10);
    backgroundList = loadTextures(1, 1);

    
    int running = TRUE;
    
    DGL_Vec2 pos = { 0, 0 };
    DGL_Vec2 off = { 0,  0 };//                                                              front                 l                    r           top/bot
    Block* block = createBlock(scale, 1.0f, mesh, meshleft, meshright, meshtop, meshbot, textureList->textures[1]);
    Layer* layer = createLayer(pos, (DGL_Vec2) { 1.0f, 1.0f }, (DGL_Vec2) { 0.0f, 0.0f }, 1.0f, CreateMeshSheet(1920, 1080, 1, 1), backgroundList->textures[0]);
    Layer* layer2 = createLayer(pos, (DGL_Vec2) { 1.0f, 1.0f }, (DGL_Vec2) { 0.0f, 0.0f }, 1.0f, CreateMeshSheet(1920, 1080, 1, 1), backgroundList->textures[0]);
    float map[80] = { 0.0f };
    char tilemap[32][49] = {
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "................................................",
    "22222222........................................",
    "222....2........................................",
    "222....2............012345678..................1",
    "2......2......................................11",
    "2......2.....................................111",
    "2......2....................................1111",
    "2......2...................................11111",
    "222222221111111111111111111111111111111111111111",
    };


    unsigned char lightMap[64 * (64 * 4)] = { 0 };
    Layer* layer3 = createLayer(pos, (DGL_Vec2) { 1.0f, 1.0f }, (DGL_Vec2) { 0.0f, 0.0f }, 1.0f, CreateMesh(1920, 1080, 0, 1, 1), DGL_Graphics_LoadTextureFromMemory(lightMap, 64, 64));

    


    for (int n = 0; n < 78; n+=2) {
        map[n] = ((n-20.0f)/2.0f) * 64.0f;
        map[n + 1] = 0.0f*32.0f*(n-20.0f);//sinf((float)n)*2.0f;
    }
    int index = 16;
    int index2 = 8;
    float delta = 0.0f;
    float timer = 0.0f;

    int jump = 0;
    

    //DGL_Window_SetStyle(WS_EX_TOPMOST | WS_POPUP);
    while (running)
    {
    
        DGL_System_FrameControl();
        DGL_System_Update();
        DGL_Graphics_StartDrawing();
        DGL_Graphics_SetBlendMode(DGL_BM_BLEND);
        DGL_Graphics_SetShaderMode(DGL_SM_TEXTURE);
        DGL_Camera_SetZoom(0.25f);
        //drawLayer(layer2);
        //drawLayer(layer);
        layer2;
        layer;
        if (tilemap[index2 + 1][16 + (int)(off.x / scale.x)] == '.' && jump <= 0) {
            off.y += 512.0f * delta;
            
        }


        if (jump > 0) {
            off.y -= 128.0f * delta;
            layer->offset.y -= 1.0f / 640.0f * delta * 1.0f;
            jump--;
        }
        index = 16 +(int)(off.x / scale.x) * 1;
        index2 = 16 +(int)((off.y - 0.0f) / scale.y) * 1;

        drawTilemap(tilemap, (DGL_Vec2){off.x, off.y - 0.0f}, index, index2, block, textureList);

        
        DGL_Graphics_SetTexture(textureList->textures[9]);
        DGL_Graphics_SetCB_TextureOffset(&(DGL_Vec2) { 0, 0 });
        DGL_Graphics_SetCB_TransformData(&(DGL_Vec2) {0,0}, & (DGL_Vec2) { 64.0f, 64.0f }, 0.0f);
        //DGL_Graphics_DrawMesh(tempmesh, DGL_DM_TRIANGLELIST);

        tempmesh;
        timer+=(1.0f/256.0f)*5.0f;
        

        drawLayer(layer3);
        //printf("%f \n", timer);

        delta = (float)DGL_System_GetDeltaTime();
        if (DGL_Input_KeyDown(VK_UP)) {
            off.y += 128.0f * delta;
            layer->offset.y += 1.0f / 640.0f * delta * 1.0f;
        }
        if (DGL_Input_KeyDown(VK_DOWN)) {
            off.y -= 128.0f * delta;
            layer->offset.y -= 1.0f / 640.0f * delta * 1.0f;
        }
        if (DGL_Input_KeyDown(VK_LEFT)) {
            off.x -= 128.0f * delta;
            layer->offset.x -= 1.0f / 640.0f * delta * 1.0f;
        }
        if (DGL_Input_KeyDown(VK_RIGHT)) {
            off.x += 128.0f * delta;
            layer->offset.x += 1.0f / 640.0f * delta * 1.0f;
        }

        if (DGL_Input_KeyTriggered('Z')) {
            jump = 60;
            printf("Hey");
            
        }



        if (DGL_Input_KeyDown('1')) {
            block->depth+= 0.1f;
        }
        if (DGL_Input_KeyDown('2')) {
            block->depth-= 0.1f;
        }
        if (DGL_Input_KeyTriggered(VK_SPACE)) {
            printf("OFFX: %f   OFFY: %f   DEPTH: %f\n", off.x, off.y, block->depth);
            printf("FPS : %f\n", 1.0f / DGL_System_GetDeltaTime());
            printf("INDEX : %i\n", index);
            for (int i = 0; i < (64*(64*4)); i+=4) {
                lightMap[i + 0] = 0;
                lightMap[i + 1] = 0;
                lightMap[i + 2] = 0;
                lightMap[i + 3] = 255;
            
            
                if (Dist2D((float)((i/4) % 64), (float)(i / (64 * 4)), 32, 32) < 16) {
                    lightMap[i + 3] = (unsigned char)(Dist2D((float)((i / 4) % 64), (float)(i / (64 * 4)), 32, 32)/16 * 255);
                    //printf("%i %i %f\n", (i % (64 * 4)) / 4, i / (64 * 4), fabsf(Dist2D((float)(i % (64 * 4)) / 4, (float)i / (64 * 4), 32, 32) * 2));
                }
               
            }
            DGL_Graphics_FreeTexture(&layer3->toptex);
            layer3->toptex = DGL_Graphics_LoadTextureFromMemory(lightMap, 64, 64);

            //layer->toptex = texture5;
            //if (layer2->toptex == texture7) {
            //    layer2->toptex = texture6;
            //}
            //else {
            //    layer2->toptex = texture7;
            //}
            //
            //if (block->fronttex == textureList[1]) {
            //    block->fronttex = textureList[2];
            //}
            //else {
            //    block->fronttex = textureList[1];
            //}


            
            
        }
        DGL_Graphics_FinishDrawing();
        if (!DGL_System_DoesWindowExist() || DGL_Input_KeyTriggered(VK_ESCAPE)) {
            running = FALSE;
            exitWindow();
        }
    }
    DGL_System_Exit();
    return 0;
}


