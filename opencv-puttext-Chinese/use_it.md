###在cmakelist中添加
```
include_directories(/usr/include/freetype2)
add_executable(detectPlateAdas test/detectPlateADAS.cpp test/OpencvText.cpp)
target_link_libraries(detectPlateAdas ... freetype)
```

###在主函数中
```
std::shared_ptr<Cv310Text> put_text_ptr_ = std::make_shared<Cv310Text>(font_path.c_str(), 30);
put_text_ptr_->putText(bgr_frame, face_names[i].c_str(), cv::Point(left + 6, bottom - 6), cv::Scalar(255, 255, 255));
```


========================================
lib的形式
###在cmakelist中添加
add_library(chinesetext SHARED putChineseText/OpencvText.cpp)
target_link_libraries(chinesetext freetype ${OpenCV_LIBS})
