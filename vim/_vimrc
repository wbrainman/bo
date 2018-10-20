set nocompatible
filetype off  
" 此处规定Vundle的路径  
set rtp+=$VIM/vimfiles/bundle/vundle/  
call vundle#rc('$VIM/vimfiles/bundle/')  
Bundle 'gmarik/vundle'  
filetype plugin indent on  
  
" original repos on github<br>Bundle 'mattn/zencoding-vim'  
Bundle 'drmingdrmer/xptemplate'  
   
" vim-scripts repos  
" Bundle 'L9'  
" Bundle 'FuzzyFinder'  
" Bundle 'bufexplorer.zip'  
Bundle 'taglist.vim'  
" Bundle 'The-NERD-tree'  
" Bundle 'matrix.vim'  
" Bundle 'closetag.vim'  
" Bundle 'The-NERD-Commenter'  
" Bundle 'matchit.zip'  
" Bundle 'AutoComplPop'  
" Bundle 'jsbeautify'  
" Bundle 'YankRing.vim'  
Bundle 'scrooloose/nerdtree.git'  
Bundle 'Lokaltog/vim-powerline.git'  
Bundle 'aceofall/gtags.vim' 
Bundle 'szw/vim-tags.git'
Bundle 'ervandew/supertab.git'
Bundle 'Shougo/neocomplete.vim.git'
Bundle 'vim-scripts/Mark--Karkat.git'
Bundle 'kien/ctrlp.vim'
Bundle 'vim-scripts/a.vim.git'
filetype plugin indent on     " required! 

set nu
colorscheme molokai
""colorscheme desert
set background=dark
syntax on
set tabstop=4
set expandtab
set shiftwidth =4                   "设置当行之间交错时使用4个空格 
set showmatch                     "设置匹配模式，类似当输入一个左括号时会匹配相应的右括号
set guioptions-=T                 "去除vim的GUI版本中得toolbar  
set incsearch                        "在程序中查询一单词，自动匹配单词的位置；如查询desk单词，当输到/d时
set nowritebackup					"backup swap file
set nobackup
set noswapfile
set encoding=utf-8
set fileformats=unix,dos
set hlsearch
set guioptions-=m				"隐藏工具栏
set cursorline					"高亮行
"hi CursorLine   cterm=NONE ctermbg=Gray ctermfg=Black     guibg=Gray guifg=Black    


if has("gui_running")
  if has("gui_gtk2")
    set guifont=Inconsolata\ 12
  elseif has("gui_macvim")
    set guifont=Menlo\ Regular:h14
  elseif has("gui_win32")
    set guifont=Consolas:h12:cANSI
  endif
endif
"
" 下面5行用来解决gVim菜单栏和右键菜单乱码问题  
set encoding=utf8  
set langmenu=zh_CN.UTF-8  
set imcmdline  
source $VIMRUNTIME/delmenu.vim  
source $VIMRUNTIME/menu.vim  
" 解决gVim中提示框乱码  
language message zh_CN.UTF-8

"============================================================="
" 				NERDTree setup 	 							  "
"============================================================="
"close vim if the only window left open is a NERDTree
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTreeType") &&b:NERDTreeType == "primary") | q | endif

"============================================================="
" 				power line setup  							  "
"============================================================="
let g:Powerline_symbols = 'fancy'

"============================================================="
" 				gtags setup 	  							  "
"============================================================="
map <F6>  :exec "!gtags &"<cr>
let Gtags_OpenQuickfixWindow = 1
"不用altkeys映射到窗口列表
set winaltkeys=no

set cscopetag " 使用 cscope 作为 tags 命令
set cscopeprg='gtags-cscope' " 使用 gtags-cscope 代替 cscope
" gtags.vim 设置项
let GtagsCscope_Auto_Load = 1
let CtagsCscope_Auto_Map = 1
let GtagsCscope_Quiet = 1

map <C-n> :cn<cr>
map <C-m> :cp<cr>
map <C-l> :cl<cr>
"============================================================="
" 				neocomplete setup 							  "
"============================================================="
" Disable AutoComplPop.
let g:acp_enableAtStartup = 1
" Use neocomplete.
let g:neocomplete#enable_at_startup = 1
" Use smartcase.
let g:neocomplete#enable_smart_case = 1
" Set minimum syntax keyword length.
let g:neocomplete#sources#syntax#min_keyword_length = 3
let g:neocomplete#lock_buffer_name_pattern = '\*ku\*'

" Define dictionary.
let g:neocomplete#sources#dictionary#dictionaries = {
    \ 'default' : '',
    \ 'vimshell' : $HOME.'/.vimshell_hist',
    \ 'scheme' : $HOME.'/.gosh_completions'
        \ }

" Define keyword.
if !exists('g:neocomplete#keyword_patterns')
    let g:neocomplete#keyword_patterns = {}
endif
let g:neocomplete#keyword_patterns['default'] = '\h\w*'

" Plugin key-mappings.
inoremap <expr><C-g>     neocomplete#undo_completion()
inoremap <expr><C-l>     neocomplete#complete_common_string()

" Recommended key-mappings.
" <CR>: close popup and save indent.
inoremap <silent> <CR> <C-r>=<SID>my_cr_function()<CR>
function! s:my_cr_function()
  return (pumvisible() ? "\<C-y>" : "" ) . "\<CR>"
  " For no inserting <CR> key.
  "return pumvisible() ? "\<C-y>" : "\<CR>"
endfunction
" <TAB>: completion.
inoremap <expr><TAB>  pumvisible() ? "\<C-n>" : "\<TAB>"
" <C-h>, <BS>: close popup and delete backword char.
inoremap <expr><C-h> neocomplete#smart_close_popup()."\<C-h>"
inoremap <expr><BS> neocomplete#smart_close_popup()."\<C-h>"
" Close popup by <Space>.
"inoremap <expr><Space> pumvisible() ? "\<C-y>" : "\<Space>"

" AutoComplPop like behavior.
"let g:neocomplete#enable_auto_select = 1

" Shell like behavior(not recommended).
"set completeopt+=longest
"let g:neocomplete#enable_auto_select = 1
"let g:neocomplete#disable_auto_complete = 1
"inoremap <expr><TAB>  pumvisible() ? "\<Down>" : "\<C-x>\<C-u>"

" Enable omni completion.
autocmd FileType css setlocal omnifunc=csscomplete#CompleteCSS
autocmd FileType html,markdown setlocal omnifunc=htmlcomplete#CompleteTags
autocmd FileType javascript setlocal omnifunc=javascriptcomplete#CompleteJS
autocmd FileType python setlocal omnifunc=pythoncomplete#Complete
autocmd FileType xml setlocal omnifunc=xmlcomplete#CompleteTags

" Enable heavy omni completion.
if !exists('g:neocomplete#sources#omni#input_patterns')
  let g:neocomplete#sources#omni#input_patterns = {}
endif
"let g:neocomplete#sources#omni#input_patterns.php = '[^. \t]->\h\w*\|\h\w*::'
"let g:neocomplete#sources#omni#input_patterns.c = '[^.[:digit:] *\t]\%(\.\|->\)'
"let g:neocomplete#sources#omni#input_patterns.cpp = '[^.[:digit:] *\t]\%(\.\|->\)\|\h\w*::'

" For perlomni.vim setting.
" https://github.com/c9s/perlomni.vim
let g:neocomplete#sources#omni#input_patterns.perl = '\h\w*->\h\w*\|\h\w*::'

"==============================================="
"    CTRLP setup  								"
"==============================================="
let g:ctrlp_map = '<c-p>'
let g:ctrlp_cmd = 'CtrlP'
let g:ctrlp_working_path_mode = 'ra'
let g:ctrlp_by_filename = 1

"When invoked, unless a starting directory is specified, CtrlP will set its local working directory according to this variable:
let g:ctrlp_working_path_mode = 'ra'
"'c' - the directory of the current file.
"'r' - the nearest ancestor that contains one of these directories or files: .git .hg .svn .bzr _darcs
"'a' - like c, but only if the current working directory outside of CtrlP is not a direct ancestor of the directory of the 
"current file.
"0 or '' (empty string) - disable this feature.
"
"Exclude files and directories using Vim's wildignore and CtrlP's own g:ctrlp_custom_ignore:

set wildignore+=*/tmp/*,*.so,*.swp,*.zip     " MacOSX/Linux
set wildignore+=*\\tmp\\*,*.swp,*.zip,*.exe,*.o  " Windows


let g:ctrlp_custom_ignore = '\v[\/]\.(git|hg|svn|debug)$'
let g:ctrlp_custom_ignore = '\v\.(exe|so|dll|zip|tar|tar.gz|pyc|o)$'

"Use a custom file listing command:
let g:ctrlp_user_command = 'find %s -type f'        " MacOSX/Linux
let g:ctrlp_user_command = 'dir %s /-n /b /s /a-d'  " Windows

"A.vim
nnoremap <silent> <F4> :A<CR>

"taglist set up
let Tlist_Use_Right_Window = 1

"相对行号
set relativenumber

set fdm=marker
"manual          手工定义折叠         
"indent           更多的缩进表示更高级别的折叠         
"expr              用表达式来定义折叠         
"syntax           用语法高亮来定义折叠         
"diff                对没有更改的文本进行折叠         
"marker           对文中的标志折叠
"zc      折叠
"zC     对所在范围内所有嵌套的折叠点进行折叠
"zo      展开折叠
"zO     对所在范围内所有嵌套的折叠点展开
"[z       到当前打开的折叠的开始处。
"]z       到当前打开的折叠的末尾处。
"zj       向下移动。到达下一个折叠的开始处。关闭的折叠也被计入。
"zk      向上移动到前一折叠的结束处。关闭的折叠也被计入。
"zf      创建折叠，比如在marker方式下：                  
"         zf56G，创建从当前行起到56行的代码折叠；                  
"         10zf或10zf+或zf10↓，创建从当前行起到后10行的代码折叠。                  
"         10zf-或zf10↑，创建从当前行起到之前10行的代码折叠。                  
"         在括号处zf%，创建从当前行起到对应的匹配的括号上去（（），{}，[]，<>等）。
" 
"zd      删除 (delete) 在光标下的折叠。
"         仅当 'foldmethod' 设为 manual 或 marker 时有效。
" 
"zD     循环删除 (Delete) 光标下的折叠，即嵌套删除折叠。
"         仅当 'foldmethod' 设为 manual 或 marker 时有效。
" 
"zE      除去 (Eliminate) 窗口里“所有”的折叠。
"         仅当 'foldmethod' 设为 manual 或 marker 时有效。
