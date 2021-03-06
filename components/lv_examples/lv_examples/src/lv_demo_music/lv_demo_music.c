/**
 * @file lv_demo_music.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_demo_music.h"

#if LV_USE_DEMO_MUSIC

#include "lv_demo_music_main.h"
#include "lv_demo_music_list.h"

/*********************
 *      DEFINES
 *********************/
#define LV_DEMO_MUSIC_AUTO_PLAY 1

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
#if LV_DEMO_MUSIC_AUTO_PLAY
static void auto_step_cb(lv_timer_t * timer);
#endif

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t * ctrl;
static lv_obj_t * list;

static const char * title_list[] = {
    "Waiting for true love",
    "Need a Better Future",
    "Vibrations",
    "Why now?",
    "Never Look Back",
    "It happened Yesterday",
    "Feeling so High",
    "Go Deeper",
    "Find You There",
    "Until the End",
};

static const char * artist_list[] = {
    "The John Smith Band",
    "My True Name",
    "Robotics",
    "John Smith",
    "My True Name",
    "Robotics",
    "Robotics",
    "Unknown artist",
    "Unknown artist",
    "Unknown artist",
};

static const char * genre_list[] = {
    "Rock • 1997",
    "Drum'n bass • 2016",
    "Psy trance • 2020",
    "Metal • 2015",
    "Metal • 2015",
    "Metal • 2015",
    "Metal • 2015",
    "Metal • 2015",
    "Metal • 2015",
    "Metal • 2015",
};

static const uint32_t time_list[] = {
    1*60 + 14,
    2*60 + 26,
    1*60 + 54,
    2*60 + 24,
    2*60 + 37,
    3*60 + 33,
    1*60 + 56,
    3*60 + 31,
    2*60 + 20,
    2*60 + 19,
};

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_demo_music(void)
{
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0x343247), 0);

    list = _lv_demo_music_list_create(lv_scr_act());
    ctrl = _lv_demo_music_main_create(lv_scr_act());

#if LV_DEMO_MUSIC_AUTO_PLAY
    lv_timer_create(auto_step_cb, 1000, NULL);
#endif
}

const char * _lv_demo_music_get_title(uint32_t track_id)
{
    if(track_id >= sizeof(title_list) / sizeof(title_list[0])) return NULL;
    return title_list[track_id];
}

const char * _lv_demo_music_get_artist(uint32_t track_id)
{
    if(track_id >= sizeof(artist_list) / sizeof(artist_list[0])) return NULL;
    return artist_list[track_id];
}

const char * _lv_demo_music_get_genre(uint32_t track_id)
{
    if(track_id >= sizeof(genre_list) / sizeof(genre_list[0])) return NULL;
    return genre_list[track_id];
}

uint32_t _lv_demo_music_get_track_length(uint32_t track_id)
{
    if(track_id >= sizeof(time_list) / sizeof(time_list[0])) return 0;
    return time_list[track_id];
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#if LV_DEMO_MUSIC_AUTO_PLAY
static void auto_step_cb(lv_timer_t * t)
{
    LV_FONT_DECLARE(lv_demo_music_font_16_bold)
    static uint32_t state = 0;

    switch(state) {
    case 5:
        _lv_demo_music_album_next(true);
        break;

    case 6:
        _lv_demo_music_album_next(true);
        break;
    case 7:
        _lv_demo_music_album_next(true);
        break;
    case 8:
        _lv_demo_music_play(0);
        break;
    case 12:
        lv_obj_scroll_by(ctrl, 0, -LV_VER_RES, LV_ANIM_ON);
        break;
    case 14:
//        lv_obj_scroll_by(ctrl, 0, -LV_VER_RES, LV_ANIM_ON);
        break;
    case 15:
        lv_obj_scroll_by(list, 0, -300, LV_ANIM_ON);
        break;
    case 16:
        lv_obj_scroll_by(list, 0, 300, LV_ANIM_ON);
        break;
//        lv_anim_init(&a);
//        lv_anim_set_var(&a, list);
//        lv_anim_set_values(&a, lv_obj_get_y(list), -lv_obj_get_height(list) + LV_DEMO_MUSIC_HANDLE_SIZE);
//        lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t) lv_obj_set_y);
//        lv_anim_set_time(&a, 1000);
//        lv_anim_set_playback_time(&a, 1000);
//        lv_anim_set_playback_delay(&a, 200);
//        lv_anim_start(&a);
        break;
    case 18:
        _lv_demo_music_play(1);
        break;
    case 19:
        lv_obj_scroll_by(ctrl, 0, LV_VER_RES, LV_ANIM_ON);
        break;
    case 30:
        _lv_demo_music_play(2);
        break;
    case 40: {
          lv_obj_t * bg = lv_layer_top();
          lv_obj_set_style_bg_color(bg, lv_color_hex(0x6f8af6), 0);
          lv_obj_set_style_text_color(bg, lv_color_white(), 0);
          lv_obj_set_style_bg_opa(bg, LV_OPA_COVER, 0);
          lv_obj_fade_in(bg, 400, 0);
          lv_obj_t * dsc = lv_label_create(bg);
          lv_obj_set_style_text_font(dsc, &lv_font_montserrat_14, 0);
          lv_label_set_text(dsc, "The average FPS is");
          lv_obj_align(dsc, LV_ALIGN_TOP_MID, 0, 90);

          lv_obj_t * num = lv_label_create(bg);
          lv_obj_set_style_text_font(num, &lv_demo_music_font_16_bold, 0);
#if LV_USE_PERF_MONITOR
          lv_label_set_text_fmt(num, "%d", lv_refr_get_fps_avg());
#endif
          lv_obj_align(num, LV_ALIGN_TOP_MID, 0, 120);

          lv_obj_t * attr = lv_label_create(bg);
          lv_obj_set_style_text_align(attr, LV_TEXT_ALIGN_CENTER, 0);
          lv_obj_set_style_text_font(attr,&lv_font_montserrat_12, 0);
#if LV_DEMO_MUSIC_SQUARE
          lv_label_set_text(attr, "Copyright 2020 LVGL Kft.\nwww.lvgl.io | lvgl@lvgl.io");
#else
          lv_label_set_text(attr, "Copyright 2020 LVGL Kft. | www.lvgl.io | lvgl@lvgl.io");
#endif
          lv_obj_align(attr, LV_ALIGN_BOTTOM_MID, 0, -10);
          break;
    }
    case 41:
        lv_scr_load(lv_obj_create(NULL));
        _lv_demo_music_pause();
        break;
    }
    state++;

}

#endif /*LV_DEMO_MUSIC_AUTO_PLAY*/

#endif /*LV_USE_DEMO_MUSIC*/
