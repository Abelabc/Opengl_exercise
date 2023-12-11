# Learn_opengl实战

![](https://img.shields.io/github/stars/pandao/editor.md.svg) ![](https://img.shields.io/github/forks/pandao/editor.md.svg) ![](https://img.shields.io/github/tag/pandao/editor.md.svg) ![](https://img.shields.io/github/release/pandao/editor.md.svg) ![](https://img.shields.io/github/issues/pandao/editor.md.svg) ![](https://img.shields.io/bower/v/editor.md.svg)
## 00_window

实现了窗口的调用

## 01_triangle

实现了多个三角形绘制，使用EBO去管理重复顶点

学会了多个输出方式LINE、LOOP、FILL

学会了动态编译多个着色器和链接
```
//参数0表示顶点属性数组的索引。
glEnableVertexAttribArray(0);
```
<div align=center>
<img src="https://github.com/Abelabc/learn_opengl/blob/main/pic/two_triangle.png" width="400" height="400">
</div>

## 02_GLSL
GLSL学习，并且实现了不同着色器渲染不同三角形

<div align=center>
<img src="https://github.com/Abelabc/learn_opengl/blob/main/pic/two_triangle.png" width="400" height="400">
</div>

## 03_GLSL

实现了在一个数组中按照自定义规则设置顶点属性指针

uniform、glUniform1i 和 glGetUniformLocation 的使用
```
// 设置顶点属性指针
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
```
<div align=center>
<img src="https://github.com/Abelabc/learn_opengl/blob/main/pic/tri_color.png" width="400" height="400">
</div>

## 04_shader_class
实现了shader.h头文件编写，不必再字符串流动态编译了。

编写glsl文件并且根据它们穿见着色器。

实现了根据时间变化位置的三角形。

<div align=center>
<img src="https://github.com/Abelabc/learn_opengl/blob/main/pic/moving_tri4.gif" width="400" height="400">
</div>

## 05_texture

实现了纹理贴图

实现了多纹理贴图，在循环中调用以下代码进行组合

```
      glActiveTexture(GL_TEXTURE0);
      glBindTexture(GL_TEXTURE_2D, texture1);

      glActiveTexture(GL_TEXTURE1);
      glBindTexture(GL_TEXTURE_2D, texture2);
```

<div align=center>
<img src="https://github.com/Abelabc/learn_opengl/blob/main/pic/mix_tex.png" width="400" height="400">
</div>

## 06_GLM

练习了glm的一些操作：

rotate函数参数分别为矩阵、参数、旋转轴

scale函数参数分别为矩阵、各方向比例向量
```
	trans = glm::rotate(trans,  (float)(glm::radians(30.f*glfwGetTime())), glm::vec3(0.0, 0.0, 1.0));
        trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
```
<div align=center>
<img src="https://github.com/Abelabc/learn_opengl/blob/main/pic/glm_rotate.gif" width="400" height="400"><img src="https://github.com/Abelabc/learn_opengl/blob/main/pic/scale.gif" width="400" height="400">
</div>


## 07_3D

学习MVP变换
<div align=center>
<img src="https://github.com/Abelabc/learn_opengl/blob/main/pic/tuto.png" width="400" height="300">
</div>
实现了model、view、projection三种矩阵，左乘矩阵就是对应变化
```
        float time = glfwGetTime();
        glm::mat4 model         = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 view          = glm::mat4(1.0f);
        glm::mat4 projection    = glm::mat4(1.0f);
        model = glm::rotate(model, (float)time*glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        unsigned int viewLoc  = glGetUniformLocation(ourShader.ID, "view");
        // pass them to the shaders (3 different ways)
        ourShader.setTrans("model",1, model);
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
        ourShader.setTrans("projection",1, projection);
```
<div align=center>
<img src="https://github.com/Abelabc/learn_opengl/blob/main/pic/mvp.gif" width="400" height="400"><img src="https://github.com/Abelabc/learn_opengl/blob/main/pic/3D_rotate.gif" width="400" height="400">
</div>
