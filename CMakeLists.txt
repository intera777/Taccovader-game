# 1. CMakeの最小バージョンを指定
cmake_minimum_required(VERSION 3.10)

# 2. プロジェクト名と言語を指定
project(MyProject LANGUAGES CXX)

# 3. C++の標準規格を指定 (例: C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 4. 実行ファイルの作成
# add_executable(生成されるファイル名 ソースファイル1 ソースファイル2 ...)
add_executable(Taccovadergame background.cpp block.cpp bullet.cpp effect.cpp enemy.cpp howtooperate.cpp main_function.cpp score.cpp sentence.cpp sound.cpp user.cpp main.cpp)