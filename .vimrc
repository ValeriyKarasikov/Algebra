" YouCompleteMe
"{
let g:ycm_show_diagnostics_ui = 1 " enable visualization of errors and warnings
"let g:ycm_global_ycm_extra_conf = '~/.ycm_extra_conf.py'
let g:ycm_use_clangd = 1
let g:ycm_always_populate_location_list = 1 " :ln (:lnext), :lp (lprevious)
map <F9> :YcmShowDetailedDiagnostic <CR>
"}

" Vim-CMake
"{
let g:cmake_default_config='build'

nmap <leader>cg <Plug>(CMakeGenerate)
nmap <leader>cb <Plug>(CMakeBuild)
nmap <leader>ci <Plug>(CMakeInstall)
nmap <leader>cs <Plug>(CMakeSwitch)
nmap <leader>cq <Plug>(CMakeClose)
"}

" Vimspector
"{
nnoremap <leader>dd :call vimspector#Launch()<CR>
nnoremap <leader>de :call vimspector#Reset()<CR>

nmap <leader>dl <Plug>VimspectorStepInto
nmap <leader>dj <Plug>VimspectorStepOver
nmap <leader>dk <Plug>VimspectorStepOut
nmap <leader>d_ <Plug>VimspectorRestart
nnoremap <leader>d<space> :call vimspector#Continue()<CR>

nmap <leader>drc <Plug>VimspectorRunToCursor
nmap <leader>dbp <Plug>VimspectorToggleBreakpoint
nmap <leader>dcbp <Plug>VimspectorToggleConditionalBreakpoint

nnoremap <leader>dc :call GotoWindow(g:vimspector_session_windows.code)<CR>
nnoremap <leader>dt :call GotoWindow(g:vimspector_session_windows.tagpage)<CR>
nnoremap <leader>dv :call GotoWindow(g:vimspector_session_windows.variables)<CR>
nnoremap <leader>dw :call GotoWindow(g:vimspector_session_windows.watches)<CR>
nnoremap <leader>ds :call GotoWindow(g:vimspector_session_windows.stack_trace)<CR>
nnoremap <leader>do :call GotoWindow(g:vimspector_session_windows.output)<CR>
"}

" Keybindings
"{
" Build using makeprg:
map <F6> :make build <CR>
" Clean using makeprg:
map <F7> :make clean <CR>
" Run program in vertical tab:
map <F8> :vert term ./build/launcher while :; do sl; done <CR>
"map <F8> :vert term ./build/launcher -term 2> >(tee -a error.log >&2) while :; do sl; done <CR>
"}

" Version: 2021.07.15
