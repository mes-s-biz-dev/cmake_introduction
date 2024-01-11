# CMake Introduction

## 1. What is CMake?

ビルドシステムにはいくつか種類がありますがもっとも有名なものとしてはMakeがあります。
MakeはMakefileを記述することによりビルドが可能になりますが記述が複雑で速度が遅いため敬遠されます。
近年ではMakeより5~10倍高速なNinjaというビルドシステムを利用するケースが増えていますがそのスクリプトは
Makefile以上にマシンリーダブルなものであるためもはや人間の手では保守不可能です。

そこで登場したのがCMakeです。
CMakeはMakeやNinjaにとってかわるものではなく、CMakeLists.txtというファイルから
開発者の環境に合わせたビルドスクリプトを生成し、ビルドするためのツールです。
すなわちMakeやNinjaを補完するためのツールと考えたほうがよいでしょう。
GUIによるサポートもあるため初心者でも使いやすいです。

C++ BuilderにおいてもMakefileを使用してMakeが可能でしたが、現在はNinjaとCMakeをサポートしています。
CMakeを使用し、これまで通りのMakefileを作成することも可能です。
vclやfire monkeyアプリケーションもCMakeを利用することで簡単に作成できるようになるのでぜひ導入しましょう。

## 2. How to set up?

手順はEmbacadero社の公式サイトにも記載があります。

[https://docwiki.embarcadero.com/RADStudio/Sydney/en/Using_CMake_with_C%2B%2B_Builder
](https://docwiki.embarcadero.com/RADStudio/Sydney/en/Using_CMake_with_C%2B%2B_Builder)

ただし、vclのビルドスクリプトに致命的な誤りがあり、Formアプリケーションとしてビルドする際に注意が必要です。

### 2.1 Install CMake and Ninja

CMakeのインストーラを以下のサイトからダウンロードします。(cmake-3.28.1-windows-x86_64.msi)

[https://cmake.org/download/](https://cmake.org/download/)

インストールの際CMakeをシステムパスに含めるチェックボックスのチェックが外れているためチェックいれておいてください。

次にNinjaをインストールします。Ninjaは以下から単独のバイナリとして取得できます。

[https://github.com/ninja-build/ninja/releases](https://github.com/ninja-build/ninja/releases)

ninja-win.zipをダウンロードし展開後ninja.exeへのシステムパスを通します。
パスを通すのが面倒であった場合、以下の方法も有効です。

まず、コマンドプロンプトからcmakeの実行ファイルのパスを確認します。

``` bat
where cmake
```

あとはcmakeの実行ファイルのあるフォルダにninja.exeを移動させるだけです。

### 2.2 Exchange cmake script

CMakeにはインストール時に既にC++Builder用のスクリプトが含まれています。

%CMakeのインストールフォルダ%\share\cmake-3.28\Modules\Platform\Windows-Embarcadero.cmake

ただ、上記スクリプトは古いものであるため公式サイトでは以下のフォルダに配置されたファイルと置き換える
ように記載があります。(ファイルパスは環境に応じて読み替えてください。)

C:\Program Files (x86)\Embarcadero\Studio\21.0\cmake\Windows-Embarcadero.cmake

しかし、置き換えるスクリプトにも不備があるため、本リポジトリ中のWindows-Embarcadero.cmakeファイルに
置き換えるか、上記ファイル中のの下記部分を修正する必要があります。

``` diff
macro(set_embt_target)
  foreach(arg IN ITEMS ${ARGN})
    if(${arg} STREQUAL "FMX")
      set(CMAKE_${_lang}_FLAGS "${CMAKE_${_lang}_FLAGS} ${_tF}")
      include_directories(SYSTEM "${ROOTDIR}/include/windows/fmx")
    elseif(${arg} STREQUAL "VCL")
      set(CMAKE_${_lang}_FLAGS "${CMAKE_${_lang}_FLAGS} ${_tV}")
      include_directories(SYSTEM "${ROOTDIR}/include/windows/vcl")
+   elseif(${arg} STREQUAL "Form")
+     set(CMAKE_${_lang}_FLAGS "${CMAKE_${_lang}_FLAGS} ${_tW}")
    elseif(${arg} STREQUAL "DR")
      set(CMAKE_${_lang}_FLAGS "${CMAKE_${_lang}_FLAGS} ${_tJ}")
    elseif(${arg} STREQUAL "DynamicRuntime")
      set(CMAKE_${_lang}_FLAGS "${CMAKE_${_lang}_FLAGS} ${_tR}")
    elseif(${arg} STREQUAL "Package")
      set(CMAKE_${_lang}_FLAGS "${CMAKE_${_lang}_FLAGS} ${_tP}")
    elseif(${arg} STREQUAL "Unicode")
      set(CMAKE_${_lang}_FLAGS "${CMAKE_${_lang}_FLAGS} ${_tU}")
    else()
      message("Error in set_embt_target: unknown target specified \"${arg}\"")
    endif()
  endforeach()
endmacro()

```

### 2.3 Why do above?

bcc32cでは、CUI/GUIのコンパイルスイッチをエントリポイント関数

- int _tmain() 
- int WINAPI _tWinMain() 

で切り替えて実現しますが、GUIをコマンドラインからコンパイルする場合はそれに加えてコンパイルオプションに-tWというフラグが必要になります。FormアプリケーションはGUIとしてコンパイルする必要があるため上記スクリプトにそのためのフラグを追加しています。

これは以下でも報告されています。

[https://en.delphipraxis.net/topic/5699-cmake-and-vcl-application/](https://en.delphipraxis.net/topic/5699-cmake-and-vcl-application/)

2021年の報告にもかかわらず現在誰からも有効な回答がありません。心優しいどなたかがTotteKarlsson氏に手を差し伸べることを願っています。(岡野の拙い英語力では彼を救えません。)

## 3. Demo

フォルダ直下にあるbuild.batを実行します。
するとbuildというフォルダが生成されbuild\vcl\hello_world\HelloWorldApp.exeとbuild\vcl\with_console\WithConsoleApp.exeが生成されます。

## 4. How to Write CMakeLists.txt?

以下のサイトが参考になります。

[https://qiita.com/shohirose/items/45fb49c6b429e8b204ac](https://qiita.com/shohirose/items/45fb49c6b429e8b204ac)



