/**********************************************************
 *  @brief   Window width
 *********************************************************/
#define WIN_WIDTH 800

/**********************************************************
 *  @brief   Window height
 *********************************************************/
#define WIN_HEIGHT 1024

/**********************************************************
 *  @brief   Scale factor for the backgound image in x-axis
 *********************************************************/
#define WIN_SCALE_X 2.5f

/**********************************************************
 *  @brief   Scale factor for the backgound image in y-axis
 *********************************************************/
#define WIN_SCALE_Y 2.0f

/**********************************************************
 *  @brief   Number of sections.
 *  @details Corresponding to the maximum number of full
 * 			 pipes present in the screen. Divides the window
 * 			 in N vertical sections, used to determine the
 *  		 pipe flow.
 *********************************************************/
#define NUM_SECTIONS 3

/**********************************************************
 *  @brief   Width of each section.
 *********************************************************/
#define SECTION_GAP (WIN_WIDTH / NUM_SECTIONS)

/**********************************************************
 *  @brief   Width of each obstacle
 *********************************************************/
#define OBST_WIDTH 100

/**********************************************************
 *  @brief   Vertical space between the top and the bottom
 * 			 pipes
 *********************************************************/
#define OBST_GAP 350

/**********************************************************
 *  @brief   Velocity of the pipes moving to the left
 *********************************************************/
#define OBST_VEL -0.08f

/**********************************************************
 *  @brief   Minimum allowed position of the obstacle gap
 *			 on the vertical axis
 *********************************************************/
#define GAP_MIN (2 * OBST_GAP)

/**********************************************************
 *  @brief   Maximum allowed position of the obstacle gap
 * 			 on the vertical axis
 *********************************************************/
#define GAP_MAX (WIN_HEIGHT - GAP_MIN)

/**********************************************************
 *  @brief   Bird scale
 *********************************************************/
#define BIRD_SCALE 0.20f

/**********************************************************
 *  @brief   Bird radius
 *********************************************************/
#define BIRD_RADIUS 20

/**********************************************************
 *  @brief   Bird's maximum falling velocity
 *********************************************************/
#define VEL_MAX 0.4f

/**********************************************************
 *  @brief   Bird's minimum falling velocity
 *********************************************************/
#define VEL_MIN -0.5f

/**********************************************************
 *  @brief   Bird's flying acceleration
 *  @details Flying acceleration is higher than falling one
 *           in order to represent the effect of gravity
 *********************************************************/
#define ACC_FLY -0.01f

/**********************************************************
 *  @brief   Bird's falling acceleration
 *  @details Flying acceleration is higher than falling one
 *           in order to represent the effect of gravity
 *********************************************************/
#define ACC_FALL 0.001f

/**********************************************************
 *  @brief   Bird's max position.
 *  @details Maximum vertical position a bird can fly to
 * 			 with respect to its original position.
 *********************************************************/
#define FLY_MAX 10