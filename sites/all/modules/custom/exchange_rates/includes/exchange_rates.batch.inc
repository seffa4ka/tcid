<?php

/**
 * @file
 * Batch file.
 */

/**
 * Updated Exchange Rates.
 *
 * If time entity is not equal with current time. It creates a new entity with
 * the same value, but replaces the current time. Then save entity.
 */
function exchange_rates_update_rate($id, &$context) {

  $nowDate = strtotime(date("m/d/y", time()));
  $finalWrapper = entity_metadata_wrapper('exchange_rates_entity', $id);
  if ($finalWrapper->timestamp->value() != $nowDate) {
    $discount_values = array(
      'code' => $finalWrapper->code->value(),
      'value' => $finalWrapper->value->value(),
      'timestamp' => $nowDate,
    );
    $entity = entity_create('exchange_rates_entity', $discount_values);
    entity_save('exchange_rates_entity', $entity);
  }

  $context['results']['titles'][] = $finalWrapper->code->value();
  $context['message'] = 'Updated <em>' . $finalWrapper->code->value() . '</em>';
}

/**
 * Batch finish message.
 */
function exchange_rates_batch_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message('Updated ' . count($results['titles']) . ' currency codes:' . theme('item_list', array('items' => $results['titles'])));
  }
  else {
    drupal_set_message('Completed with errors.', 'error');
  }
}
