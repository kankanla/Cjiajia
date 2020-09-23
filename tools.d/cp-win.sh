#!/bin/csh
rm /tmp/mk-bcc.bat
cd /mnt/sabina/sdo/writing/book/cpp.new/book/examples/disk/tools.d/..
set out_dir=/home/sdo/win/prog
foreach x (*)
    if ((-d $x) && ($x != tools.d)) then
	rm -rf $out_dir/$x
	mkdir $out_dir/$x
        foreach file ($x/*)
	    sed -e 's/$//' <$file >$out_dir/$file
	end
	cp $out_dir/$x/makefile.bcc $out_dir/$x/Makefile
	echo "cd $x" >>/tmp/mk-bcc.bat
	echo "make >log"  >>/tmp/mk-bcc.bat
	echo "cd .." >>/tmp/mk-bcc.bat
    endif
end
sed -e 's/$//' </tmp/mk-bcc.bat >$out_dir/mk-bcc.bat
cd $out_dir
foreach old_file (*/*.cc)
    set new_file = $old_file:r
    set new_file = $new_file.cpp
    mv $old_file $new_file
end

