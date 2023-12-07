# Learn_opengl实战
![](https://img.shields.io/github/stars/pandao/editor.md.svg) ![](https://img.shields.io/github/forks/pandao/editor.md.svg) ![](https://img.shields.io/github/tag/pandao/editor.md.svg) ![](https://img.shields.io/github/release/pandao/editor.md.svg) ![](https://img.shields.io/github/issues/pandao/editor.md.svg) ![](https://img.shields.io/bower/v/editor.md.svg)
##00_window
实现了窗口的调用
##01_triangle
实现了多个三角形绘制，使用EBO去管理重复顶点

学会了多个输出方式LINE、LOOP、FILL

学会了动态编译多个着色器和链接
```
//参数0表示顶点属性数组的索引。
glEnableVertexAttribArray(0);
```
![](https://github.com/Abelabc/learn_opengl/blob/main/pic/two_triangle.png)

##02_GLSL
GLSL学习，并且实现了不同着色器渲染不同三角形
![](https://github.com/Abelabc/learn_opengl/blob/main/pic/two_triangle.png)
##03_GLSL
实现了在一个数组中按照自定义规则设置顶点属性指针

uniform、glUniform1i 和 glGetUniformLocation 的使用
```
// 设置顶点属性指针
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
```

![](https://github.com/Abelabc/learn_opengl/blob/main/pic/tri_color.png)

##04_GLSL
实现了shader.h头文件编写，不必再字符串流动态编译了。

编写glsl文件并且根据它们穿见着色器。

实现了根据时间变化位置的三角形。
![](https://github.com/Abelabc/learn_opengl/blob/main/pic/moving_tri4.gif)
