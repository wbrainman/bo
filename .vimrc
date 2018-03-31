"去掉讨厌的有关vi一致性模式，避免以前版本的一些bug和局限
set nocompatible

"语法高亮度显示
syntax on

"显示行号
set number
set relativenumber

"检测文件的类型
filetype off

"记录历史的行数
set history=1000

"背景使用黑色
set background=dark
set t_Co=256

"NO swp file
set noswapfile




"下面两行在进行编写代码时，在格式对起上很有用；
"第一行，vim使用自动对起，也就是把当前行的对起格式应用到下一行；
"第二行，依据上面的对起格式，智能的选择对起方式，对于类似C语言编
"写上很有用
set autoindent
set smartindent

"第一行设置tab键为4个空格，第二行设置当行之间交错时使用4个空格
set tabstop=4
set shiftwidth=4

"设置匹配模式，类似当输入一个左括号时会匹配相应的那个右括号
set showmatch

set rtp+=~/.vim/bundle/vundle/  
call vundle#rc()  
  
"let Vundle manage Vundle  
"required!   
Bundle 'gmarik/vundle'  
    
"可以通过以下四种方式指定插件的来源  
"a) 指定Github中vim-scripts仓库中的插件，直接指定插件名称即可，插件明中的空格使用-”代替。  
"Bundle 'L9'  

"b) 指定Github中其他用户仓库的插件，使用用户名/插件名称”的方式指定  
Bundle 'Valloric/YouCompleteMe'
Bundle 'kien/ctrlp.vim'
Bundle 'scrooloose/nerdtree.git'
Bundle 'vim-airline/vim-airline.git'
"c) 指定非Github的Git仓库的插件，需要使用git地址  
Bundle 'tomasr/molokai.git'
Bundle 'mbriggs/mark.vim.git'


"d) 指定本地Git仓库中的插件  
"Bundle 'file:///Users/gmarik/path/to/plugin'  

filetype plugin indent on     " required! 

":BundleList              -列举列表(也就是.vimrc)中配置的所有插件  
":BundleInstall          -安装列表中的全部插件  
":BundleInstall!         -更新列表中的全部插件  
":BundleSearch foo   -查找foo插件  
":BundleSearch! foo  -刷新foo插件缓存  
":BundleClean           -清除列表中没有的插件  
":BundleClean!          -清除列表中没有的插件  


"YCM
"
"配色
colorscheme  molokai  

"NerdTree
"let NERDTreeQuitOnOpen=1
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTreeType") &&b:NERDTreeType == "primary") | q | endif
