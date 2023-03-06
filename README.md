# LitUnity
OpenGL学习和包装的尝试，同时深化对C++的理解，场景仿照unity的树结构，使用xml序列化。未完成

## 项目结构
LitUnity
- Library 包括外部库的头文件，lib和dll。
- LitUnity 主工程
  - includes 头文件
    - game 框架头文件
      - base 基础框架
      - event 纯模板的事件系统，未完成
      - graphics 图形部分
        - [x] animation 骨骼动画
        - [x] gl gl封装
        - [ ] light 光
        - [x] model 模型
        - [ ] post-processing 后处理
        - [ ] shadow 阴影
      - input 输入管理器
      - res 资源管理器
      - scenes 场景相关
      - utils 工具类
    - glad，glm，imgui等参与编译的库头文件
  - res 资源
  - src 源文件
    - game 框架源文件
    - lib 需要参与编译外部库源文件

## Library
已接入
- assimp 导入模型
- glfw gl窗体框架
- stb_image 导入图片
- tinyxml xml库

尚未接入
- kwk.SimpleSocket 个人基于IOCP的socket包装
- freetype-gl 字体库
- log4cxx 日志库
- imgui 用于实现引擎调试和简单UI系统

## LitUnity待办事项
- [x] Unity树形场景的模仿
- [x] 对Unity组件结构的模仿
- [x] 封装OpenGL
- [x] 简单的资源管理
- [x] 基于xml的序列化和反序列化
- [ ] 纯模板事件池
- [ ] 实现UI系统和字体库
- [ ] 日志调试系统
