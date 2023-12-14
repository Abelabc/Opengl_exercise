#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <tool/shader.h>
#include <cmath>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <tool/stb_image.h>
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);
int main()
{
    glfwInit();
    // 设置主要和次要版本
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 创建窗口对象
    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // 注册窗口变化监听
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    // 设置视口
    glViewport(0, 0, 800, 600);
    glEnable(GL_PROGRAM_POINT_SIZE);


    float vertices[180];
    std::memcpy(vertices, box1, sizeof(box1));
    glm::vec3 cubePositions[] = {
            glm::vec3( 0.0f,  0.0f,  0.0f),
            glm::vec3( 2.0f,  5.0f, -15.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-3.8f, -2.0f, -12.3f),
            glm::vec3( 2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f,  3.0f, -7.5f),
            glm::vec3( 1.3f, -2.0f, -2.5f),
            glm::vec3( 1.5f,  2.0f, -2.5f),
            glm::vec3( 1.5f,  0.2f, -1.5f),
            glm::vec3(-1.3f,  1.0f, -1.5f)
    };
    unsigned int indices[] = {
            // 注意索引从0开始!
            // 此例的索引(0,1,2,3)就是顶点数组vertices的下标，
            // 这样可以由下标代表顶点组合成矩形

            0, 1, 3, // 第一个三角形
            1, 2, 3  // 第二个三角形
    };


    // 新建一个VBO
    unsigned int VBO, VAO;
    //glGenBuffers(1, &EBO);
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);
    // 绑定VAO缓冲对象
    glBindVertexArray(VAO);
    // 把VBO绑定到GL_ARRAY_BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // 顶点缓冲对象的缓冲类型是GL_ARRAY_BUFFER。
    // 把顶点数据复制进缓冲区
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    // 复制我们的索引数组到一个索引缓冲中，供OpenGL使用
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    // 设置顶点属性指针
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5* sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0); // 解绑

    //创建纹理
    unsigned int texture2;
    int width, height, nrChannels;

    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data= stbi_load("./static/pic/12.png", &width, &height, &nrChannels, 0);

    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    stbi_image_free(data);

    Shader ourShader("./src/07_3D/shader/vertexshader.glsl", "./src/07_3D/shader/fragmentshader.glsl");
    ourShader.use();

    ourShader.setInt("texture2", 1);
    // 设置线框绘制模式
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glEnable(GL_DEPTH_TEST);

    //model=glm::rotate(model,  (float)(glm::radians(30.f)), glm::vec3(0.0, 0.0, 1.0));
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        // 渲染指令
        // ...
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);

        ourShader.use();

        float time = glfwGetTime();
        //glm::mat4 model         = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 view          = glm::mat4(1.0f);
        glm::mat4 projection    = glm::mat4(1.0f);
        //model = glm::rotate(model, (float)time*glm::radians(-55.0f), glm::vec3(1.0f, 1.0f, 0.0f));
        view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        unsigned int viewLoc  = glGetUniformLocation(ourShader.ID, "view");
        // pass them to the shaders (3 different ways)
        //ourShader.setTrans("model",1, model);
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
        ourShader.setTrans("projection",1, projection);

        glBindVertexArray(VAO); // 不需要每次都绑定，对于当前程序其实只需要绑定一次就可以了
        for(unsigned int i = 0; i < 10; i++)
        {
            glm::mat4 model= glm::mat4(1.0f);;
            model = glm::translate(model, cubePositions[i]);
           model = glm::rotate(model, (float)glm::radians(20.f*i+10*time), glm::vec3(1.0f, 1.0f, 0.0f));

                glm::mat4 tmp = glm::rotate(model, glm::radians(1.f*i),glm::vec3(1.0f, 1.0f, 0.0f));
                ourShader.setTrans("model", 1, tmp);

                glDrawArrays(GL_TRIANGLES, 0, 36);

        }
        // glDrawArrays(GL_POINTS, 0, 6);
        // glDrawArrays(GL_LINE_LOOP, 0, 6);
        //glDrawArrays(GL_TRIANGLES, 0, 36); // 顶点数组和打算绘制多少个顶点
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    //glDeleteBuffers(1, &EBO);

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}