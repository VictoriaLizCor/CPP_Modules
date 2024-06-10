#include "Point.hpp"

/**
 * @brief Calculates the cross product of two vectors in 2D space.
 *
 * The vectors are defined by three points: `a`, `b`, and `p`. The first vector
 * is formed by points `a` and `b`, and the second vector is formed by points
 * `a` and `p`.
 *
 * @param a The first point, used to form both vectors.
 * @param b The second point, used to form the first vector.
 * @param p The third point, used to form the second vector.
 * @return The cross product of the two vectors.
 */
float static crossProduct(Point a, Point b, Point p)
{
	float edge1;
	float edge2;

	edge1 = (b.getX() - a.getX()) * (p.getY() - a.getY());
	edge2 = (b.getY() - a.getY()) * (p.getX() - a.getX());
	return (edge1 - edge2);
}

/**
 * @brief Checks if a point is inside a triangle.
 *
 * This function calculates the cross product of vectors formed by the triangle's
 * vertices and the point. If the point lies on an edge or a vertex of the 
 * triangle, the function returns false. Otherwise, it checks the signs of the 
 * cross products. If all the signs are the same (either positive or negative), 
 * the point is inside the triangle.
 *
 * @param a The first vertex of the triangle.
 * @param b The second vertex of the triangle.
 * @param c The third vertex of the triangle.
 * @param point The point to check.
 * @return True if the point is inside the triangle, false otherwise.
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Compute cross products
	float crossProductAB = crossProduct(a, b, point);
	float crossProductBC = crossProduct(b, c, point);
	float crossProductCA = crossProduct(c, a, point);

	// Check if the point is on an edge or a vertex
	//float tolerance = a.epsilon();
	// if (std::abs(crossProductAB) < tolerance || std::abs(crossProductBC) < tolerance || std::abs(crossProductCA) < tolerance)
	if (crossProductAB == 0 || crossProductBC == 0 || crossProductCA == 0) {
		return false;
	}

	// Compute signs of cross products
	bool signAB = crossProductAB < 0;
	bool signBC = crossProductBC < 0;
	bool signCA = crossProductCA < 0;

	// The point is inside the triangle if all the signs are the same
	return (signAB == signBC) && (signBC == signCA);
}


// float triangleArea(Point a, Point b, Point c)
// {
// 	float term1 = a.getX() * (b.getY() - c.getY());
// 	float term2 = b.getX() * (c.getY() - a.getY());
// 	float term3 = c.getX() * (a.getY() - b.getY());
// 	float sum = term1 + term2 + term3;
// 	return (std::abs(sum) / 2.0);
// }

// bool bsp(Point a, Point b, Point c, Point point)
// {
// 	std::cout << std::fixed;
// 	std::cout.precision(12);
// 	// Calculate areas of the main triangle and sub-triangles
// 	float mainTriangleArea = triangleArea(a, b, c);
// 	float triangle1Area = triangleArea(point, b, c);
// 	float triangle2Area = triangleArea(a, point, c);
// 	float triangle3Area = triangleArea(a, b, point);

// 	// If the sum of the areas of the three sub-triangles is equal to the area of the main triangle,
// 	// then the point is inside the triangle. We use a small tolerance to account for floating point precision issues.
// 	std:: cout << "Area1 : " << triangle1Area << std::endl;
// 	std:: cout << "Area2 : " << triangle2Area << std::endl;
// 	std:: cout << "Area3 : " << triangle3Area << std::endl;
// 	std:: cout << "AreaM : " << mainTriangleArea << std::endl;
// 	std:: cout << "A1 + A2 + A3 : " << triangle1Area + triangle2Area + triangle3Area << std::endl;
// 	std::cout << "AreaM - (A1 + A2 + A2) = " 
// 	<< std::abs(mainTriangleArea - (triangle1Area + triangle2Area + triangle3Area)) << std::endl;
// 	return (std::abs(mainTriangleArea - (triangle1Area + triangle2Area + triangle3Area)) < a.epsilon());
// }

/**
 * NOTES:
 * In 2D space, the cross product of two vectors is a scalar value, unlike in 3D
 * space where it’s a vector. The cross product of two vectors A and B in 2D
 * space is defined as:
 * 
 * A×B = (Ax​⋅By) ​− (Ay​⋅Bx​)
 * 
 * Here, A = (A_x, A_y) and B = (B_x, B_y) are the two vectors, and A_x, A_y, B_x,
 * B_y are their respective x and y components.
 * 
 * The result, A × B, represents the area of the parallelogram formed by the two
 * vectors. If the vectors are unit vectors, the cross product gives the sine of
 * the angle between them.
 * 
 * The sign of the cross product can be used to determine the relative orientation
 * of the vectors:
 * 
 *     If A × B > 0, then A is to the “left” of B (counterclockwise).
 *     If A × B < 0, then A is to the “right” of B (clockwise).
 *     If A × B = 0, then A and B are collinear (they lie on the same line).
 *
 * https://math.libretexts.org/Bookshelves/Calculus/Calculus_%28OpenStax%29/12%3A_Vectors_in_Space/12.04%3A_The_Cross_Product
*/