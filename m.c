virtual double findIntersection(Ray ray){


                Vect ray_origin = ray.getRayOrigin();
                double ray_origin_x = ray_origin.getVectX();
                double ray_origin_y = ray_origin.getVectY();
                double ray_origin_z = ray_origin.getVectZ();

                Vect ray_direction = ray.getRayDirection();
                double ray_direction_x = ray_direction.getVectX();
                double ray_direction_y = ray_direction.getVectY();
                double ray_direction_z = ray_direction.getVectZ();

                Vect cone_center  = center;
                double cone_center_x = center.getVectX();
                double cone_center_y = center.getVectY();
                double cone_center_z = center.getVectZ();

        Vect diff(cone_center_x - ray_origin_x, cone_center_y - ray_origin_y + height, cone_center_z - ray_origin_z);

        //Derive the coefficients of the quadratic equation
        double a = pow(ray_direction_x, 2) + pow(ray_direction_y, 2) * ratio + pow(ray_direction_z, 2);
        double b = diff.getVectX() * ray_direction_x +  diff.getVectY() * ratio * ray_direction_y + diff.getVectZ() * ray_direction_z;

        double c = diff.getVectX() * diff.getVectX() + ratio * diff.getVectY() * diff.getVectY() + diff.getVectZ() * diff.getVectZ();

        double discriminant = b * b - a * c;
        cout << discriminant << "\n";

        if (discriminant > 0){
            //The ray intersects this cone. Find the lower root
            double root_1 = (-1 * b - discriminant)/2 - 0.000001;
                       if (root_1 > 0) {

                                // the first root is the smallest positive root
                                return root_1;
                        }
                        else {
                                // the second root is the smallest positive root
                                double root_2 = ((sqrt(discriminant) - b)/2) - 0.000001;
                                return root_2;
                        }
                }
                else {
                        // the ray missed the cone
                        return -1;

        }

    }