module breadboard() {
    rotate([0,0,90]) color([1,1,1]) difference() {
        cube([50, 43, 5]);
    
        translate([25, 3/2+2, -5]) cylinder(r=3, h=3*5);
    }
}

module arduinopromini() {
    rotate([0,0,90]) color([.2,.15,.80]) cube([33, 17, 4]);
    
    translate([0,0,4]) rotate([0,0,90]) union() {
        for(offset=[0:2.54:30]) {
            translate([offset, 0, 0]) color([.2,.2,.2]) cube(2.44);
            translate([offset+1.17,1.17,2.54+2.5]) color([.7,.7,.7]) cube([1,1,5], center=true);
        }
    }
    
    translate([-17+2.44,0,4]) rotate([0,0,90]) union() {
        for(offset=[0:2.54:30]) {
            translate([offset, 0, 0]) color([.2,.2,.2]) cube(2.44);
            translate([offset+1.17,1.17,2.54+2.5]) color([.7,.7,.7]) cube([1,1,5], center=true);
        }
    }
    
    translate([-17+1,33-2.44,4]) rotate([0,0,0]) union() {
        for(offset=[0:2.54:13]) {
            translate([offset, 0, 0]) color([.2,.2,.2]) cube(2.44);
            translate([offset+1.17,1.17,2.54+0.5]) color([.7,.7,.7]) cube([1,1,1], center=true);
            translate([offset+1.17,1.17+3,2.54+1.5]) rotate([90,0,0]) color([.7,.7,.7]) cube([1,1,7], center=true);
        }
    }
}

module 7segmentdisplay() {
    color([1,1,1]) cube([50, 19, 7]);
    translate([0,0,7]) color([0,0,0]) cube([50, 19, 1]);
    
    for(offset=[0:12.6:40]) {
        translate([offset+4,3,8]) color([0.8,0.8,0.8]) cube([4, 0.8, 0.1]);
        translate([offset+4,9,8]) color([0.8,0.8,0.8]) cube([4, 0.8, 0.1]);
        translate([offset+4,15.4,8]) color([0.8,0.8,0.8]) cube([4, 0.8, 0.1]);
    
        translate([offset+3,3,8]) color([0.8,0.8,0.8]) cube([0.8, 6.5, 0.1]);
        translate([offset+3,9.7,8]) color([0.8,0.8,0.8]) cube([0.8, 6.5, 0.1]);
        translate([offset+8.2,3,8]) color([0.8,0.8,0.8]) cube([0.8, 6.5, 0.1]);
        translate([offset+8.2,9.7,8]) color([0.8,0.8,0.8]) cube([0.8, 6.5, 0.1]);
    }
    
    color([0.7,0.7,0.7]) union() {
        for(offset=[17:3:32]) {
            translate([offset, 1, -8]) cube([1,1,15]);
        }
        
        for(offset=[17:3:32]) {
            translate([offset, 17, -8]) cube([1,1,15]);
        }
    }
}

module button() {
    $fn = 40;
    color([0.2,0.2,0.2]) cylinder(r=4.5, h=14);
    
    color([0.7,0.7,0.7]) union() {
        translate([2, -0.75, -5]) cube([0.5, 1.5, 5]);
        translate([-2, -0.75, -5]) cube([0.5, 1.5, 5]);
    }
    
    color([0.2,0.2,0.2]) translate([0,0,14]) cylinder(r1=7.5, r2=6, h=7);
    color([0.8,0.8,0.8]) translate([0,0,21]) cylinder(r=5, h=4);
}

module led(color) {
    $fn = 40;
    
    color(color) union() {
        translate([0,0,1]) cylinder(r=5, h=6);
        translate([0,0,7]) sphere(r=5);
        cylinder(r=6, h=1);
    }
    
    color([0.7,0.7,0.7]) union() {
        translate([-3,-0.5,-30]) cube([1,1,30]);
        translate([2,-0.5,-30]) cube([1,1,30]);
    }
}

module switch() {
    color([0.2,0.2,0.2]) union() {
        cube([22, 19, 12]);
    
        translate([-1,-1,12]) cube([24,21,2]); // top border
    
        translate([-2,0,-3]) rotate([0,6,0]) difference() {
            translate([1,1,17]) cube([20,17,3]); // finger pressing plate
            translate([11,20,58]) rotate([90,0,0]) cylinder(r=40, h=20);
        }
        
        translate([10.5,0,-7]) cube([1,19,7]); // bottom divider wall
    }
    
    // solder connections
    translate([4,3,-7]) rotate([0,0,-45]) color([0.7,0.7,0.7]) cube([4,0.5,7]);
    translate([4,9,-7]) rotate([0,0,-45]) color([0.7,0.7,0.7]) cube([4,0.5,7]);
    translate([15,3,-7]) rotate([0,0,-45]) color([0.7,0.7,0.7]) cube([4,0.5,7]);
    translate([15,9,-7]) rotate([0,0,-45]) color([0.7,0.7,0.7]) cube([4,0.5,7]);
}

module v9battery() {
    color([1,0,0]) cube([26,17,46]);
}


translate([100,0,0]) switch();
translate([135,0,0]) led([1,1,0]);
translate([150,0,0]) 7segmentdisplay();
translate([220,0,0]) button();
arduinopromini();