#!/usr/bin/env perl
package Codeforces::Task::_;
use v5.10;
use strict;
use warnings;


sub min{my($a,$b)=@_;if($a<$b){return$a;}else{return$b;}}
sub max{my($a,$b)=@_;if($a>$b){return$a;}else{return$b;}}

sub solve {

}

sub main {
    my $t = 1;
#    $t = int(<>);
    while ($t--) {
        solve();
    }
    return 0;
}

exit(main(@ARGV));
