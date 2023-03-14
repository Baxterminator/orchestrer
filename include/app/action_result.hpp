/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  13/03/2023
 * @description    :  File describing the results of some actions
 *========================================================================**/

#ifndef IMG_ORCH_ACTION_RESULT
#define IMG_ORCH_ACTION_RESULT

namespace img_orchestrer::app::results {

enum class Save { SAVED, SAVE_FAILED };
enum class Load { LOADED, LOAD_FAILED, NO_SELECTION };
} // namespace img_orchestrer::app::results

#endif