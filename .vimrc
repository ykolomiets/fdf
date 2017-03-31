set number
set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab
set colorcolumn=80
set textwidth=80
highlight ColorColumn ctermbg=darkgray

let g:DoxygenToolkit_authorName="Kolomiets Yaroslav <kolomiet.y.n@gmail.com>"

augroup project
	autocmd!
	autocmd BufRead, BufNewFile *.h, *.c set filetype=c.doxygen
augroup END

let &path.="./includes, ../includes"
