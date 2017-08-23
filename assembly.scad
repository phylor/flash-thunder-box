use <appliances.scad>;

module positioned_green_led() {
    translate([35,81.5,15]) rotate([-90,0,0]) led([0,1,0]);
}

module positioned_switch() {
    translate([45,73.5,25]) rotate([-90,0,0]) switch();
}

module positioned_yellow_led() {
    translate([25,24.5,42.5]) led([1,1,0]);
}

module positioned_button() {
    translate([43,24.5,33.5]) button();
}

module positioned_display() {
    translate([-35,15,40.5]) 7segmentdisplay();
}

// appliances
module appliances() {
    translate([48,5,0]) union() {
        translate([5,0,0]) breadboard();
        translate([47,0,0]) arduinopromini();
        translate([55,50,28]) rotate([90,90,0]) v9battery();

        positioned_display();
        positioned_yellow_led();
        positioned_button();

        positioned_green_led();
        positioned_switch();
    }
}

// case
width = 125;
depth = 90;
height = 45;

// Top Case
module topCase() {
    union() {
        cube([2, depth, height]); // left
        cube([width, 2, height]); // front
        
        difference() {
            union() {
                translate([0, 0, height]) cube([width, depth, 2]); // top
                translate([0, depth-2, 0]) cube([width, 2, height]); // back
            }
            
            translate([48,5,0]) union() {
                positioned_display();
                positioned_yellow_led();
                positioned_button();
                
                positioned_green_led();
                positioned_switch();
            }
        }

        translate([width-2, 0, 0]) cube([2, depth, height]); // right
        
        // screws: 3x16
        translate([2,2,0]) mountingHoleCorner(); // front left
        translate([width-2,2,0]) rotate([0,0,90]) mountingHoleCorner(); // front right
        translate([2,depth-2,0]) rotate([0,0,270]) mountingHoleCorner(); // back left
        translate([width-2,depth-2,0]) rotate([0,0,180]) mountingHoleCorner(); // back right
    }
}


// Bottom Case
module bottomCase() {
    color([1,0,0,1]) union() {
        $fn = 40;
        
        difference() {
            translate([0, 0, -2]) cube([width, depth, 2]); // bottom
            
            // front left
            translate([5,5,-4]) cylinder(r=1.5, h=6);
            translate([5,5,-2.1]) cylinder(r2=1.5, r1=3, h=1.1);
            
            // front right
            translate([width-5,5,-4]) cylinder(r=1.5, h=6);
            translate([width-5,5,-2.1]) cylinder(r2=1.5, r1=3, h=1.1);
            
            // back left
            translate([5,depth-5,-4]) cylinder(r=1.5, h=6);
            translate([5,depth-5,-2.1]) cylinder(r2=1.5, r1=3, h=1.1);
            
            // back right
            translate([width-5,depth-5,-4]) cylinder(r=1.5, h=6);
            translate([width-5,depth-5,-2.1]) cylinder(r2=1.5, r1=3, h=1.1);
        }
        translate([99, 2, 0]) cube([2, 50, height-2]); // battery divider
        translate([65, 2, 0]) cube([2, 50, height/2-2]); // arduino divider
    }
}

module mountingHoleCorner() {
    $fn = 40;
    
    difference() {
        cube([3, 3, height]);
        
        translate([3,3,-1]) cylinder(r=3, h=height+2);
    }
    
    translate([3,3,0]) mountingHole(height);
}
    
module mountingHole(height) {
    difference() {
        cylinder(r=3, h=height);
            
        translate([0,0,-1]) cylinder(r=1, h=18);
    }
}

//appliances();
topCase();
//bottomCase();